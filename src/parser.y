%{
	#include <stdbool.h>
	#include "ast.h"
	#include "main.h"

	int yylex(void);
	void yyerror(char *);
%}

%output "parser.tab.c"

%union{
	int value;
	char * name;
	struct ast * ast;
	struct attributes * attributes;
	struct patterns * patterns;
	struct pattern * pattern;
}


/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** * GESTION DES TOKENS ** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* Retourné par le scan.l */
%token < name >  TAG		// Nom de balise
%token < name >  NAME		// Variable OCaml
%token < name >  MOT		// Mot d'un texte
%token < value > NUMBER		// Un nombre

/* Tokens d'instructions CAML */
%token LET
%token REC
%token FUNC
%token IN
%token WHERE
%token IF
%token THEN
%token ELSE
%token MATCH_T
%token WITH
%token END
%token EMIT_T


%token < name >  ARROW	"=>"	// Fleche (fonction)

/* Token de comparaison */
%token < name >  OU		"||"	// OU logique
%token < name >  ET		"&&"	// ET logique
%token < name >  INF	"<"		// Inférieur relationnel
%token < name >  SUP	">"		// Supérieur relationnel
%token < name >  INF_EQ	"<="	// Inférieur ou égale relationnel
%token < name >  SUP_EQ	">="	// Supérieur ou égale relationnel
%token < name >  EQ_T	"=="	// Égale relationnel
%token < name >  NOT_EQ	"!="	// Non égale relationnel


/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ** GESTION DES TYPES ** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
%type < ast > file

/* Déclarations */
%type < ast > declarations_globales
%type < ast > declaration_locale
%type < ast > declaration
%type < ast > functions
%type < ast > names

/* Expressions CAML */
%type < ast > expr
%type < ast > conditional_expr
%type < ast > logical_expr
%type < ast > relational_expr
%type < ast > additive_expr
%type < ast > multiplicative_expr
%type < ast > negative_expr 
%type < ast > factor_expr
%type < ast > match_expr
%type < patterns > filter_expr
%type < pattern > pforests
%type < pattern > pattern_expr

/* Code XML HTML */
%type < ast > body
%type < ast > tree
%type < attributes > attributs
%type < ast > text
%type < ast > word_t


/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** *** DEBUT GRAMMAIRE *** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
%start file
%%

file
		: declarations_globales body					{ printf("lel1.1\n");$$ = mk_forest(false, $1, $2); }
		| body											{ printf("lel1.2\n");$$ = $1; emit($$, "sortie.html");}
		;

/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** *** GESTION DES DECLARATIONS DE TOUS TYPES **** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
declarations_globales
		: declaration ';' declarations_globales			{ printf("lel2.1\n");$$ = mk_forest(false, $1, $3);}
		| declaration ';'								{ printf("lel2.2\n");$$ = $1; }
		;

declaration
		: LET names '=' functions 						{ printf("lel3.1\n");ajouter_body($2->node->fun->body, $4); $$ = $2; }
		| LET REC names '=' functions 					{ printf("lel3.2\n");ajouter_body($3->node->fun->body, $5); $$ = $3; }
		;

names
		: NAME names									{ printf("lel4.1\n");$$ = mk_fun($1, $2); }
		| NAME											{ printf("lel4.2\n");$$ = mk_fun($1, NULL); }
		;

functions
		: FUNC names ARROW functions					{ printf("lel5.1\n");ajouter_body($2->node->fun->body, $4); $$ = $2; }
		| expr											{ printf("lel5.2\n");$$ = $1; }
		;
		
declaration_locale	/* Evaluation pour les IN et WHERE*/
		: LET NAME '=' factor_expr IN expr				{ printf("lel6.1\n");$$ = mk_app(mk_fun($2, $6), $4); }
		| LET REC NAME '=' factor_expr IN expr			{ printf("lel6.2\n");$$ = mk_app(mk_fun($3, $7), mk_declrec($3, $5)); }
		| factor_expr WHERE NAME '=' expr				{ printf("lel6.3\n");$$ = mk_app(mk_fun($3, $1), $5); }
		| factor_expr WHERE REC NAME '=' expr			{ printf("lel6.4\n");$$ = mk_app(mk_fun($4, $1), mk_declrec($4, $6)); }
		;

/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ** GESTION DES EXPRESSIONS OCAML ** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
expr
		: conditional_expr								{ printf("lel7.1\n");$$ = $1; }
		| declaration_locale							{ printf("lel7.2\n");$$ = $1; }
		| match_expr									{ printf("lel7.3\n");$$ = $1; }
		;

conditional_expr
		: IF logical_expr THEN expr ELSE expr			{ printf("lel8.1\n");$$ = mk_cond($2, $4, $6); }
		| logical_expr									{ printf("lel8.2\n");$$ = $1; }
		;

logical_expr
		: logical_expr OU relational_expr				{ printf("lel9.1\n");$$ = mk_app(mk_app(mk_binop(OR), $1), $3); }
		| logical_expr ET relational_expr				{ printf("lel9.2\n");$$ = mk_app(mk_app(mk_binop(AND), $1), $3); }
		| relational_expr								{ printf("lel9.3\n");$$ = $1; }
		;
		
relational_expr 
		: relational_expr INF		additive_expr		{ printf("lel10.1\n");$$ = mk_app(mk_app(mk_binop(LE), $1), $3); }
		| relational_expr SUP		additive_expr		{ printf("lel10.2\n");$$ = mk_app(mk_app(mk_binop(LEQ), $1), $3); }
		| relational_expr SUP_EQ	additive_expr		{ printf("lel10.3\n");$$ = mk_app(mk_app(mk_binop(GE), $1), $3); }
		| relational_expr INF_EQ	additive_expr		{ printf("lel10.4\n");$$ = mk_app(mk_app(mk_binop(GEQ), $1), $3); }
		| relational_expr EQ_T		additive_expr		{ printf("lel10.5\n");$$ = mk_app(mk_app(mk_binop(EQ), $1), $3); }
		| relational_expr NOT_EQ	additive_expr		{ printf("lel10.6\n");$$ = mk_app(mk_app(mk_binop(NEQ), $1), $3); }
		| additive_expr									{ printf("lel10.7\n");$$ = $1; }
		;

additive_expr
		: additive_expr '+' multiplicative_expr			{ printf("lel11.1\n");$$ = mk_app(mk_app(mk_binop(PLUS), $1), $3); }
		| additive_expr '-' multiplicative_expr			{ printf("lel11.2\n");$$ = mk_app(mk_app(mk_binop(MINUS), $1), $3); }
		| multiplicative_expr							{ printf("lel11.3\n");$$ = $1; }
		;

multiplicative_expr
		: multiplicative_expr '*'  negative_expr		{ printf("lel12.1\n");$$ = mk_app(mk_app(mk_binop(MULT), $1), $3); }
		| multiplicative_expr '/' negative_expr			{ printf("lel12.2\n");$$ = mk_app(mk_app(mk_binop(DIV), $1), $3); }
		| negative_expr									{ printf("lel12.3\n");$$ = $1; }
		;

negative_expr
		: factor_expr									{ printf("lel13.1\n");$$ = $1; }
		| '!' factor_expr								{ printf("lel13.2\n");$$ = mk_app(mk_unaryop(NOT), $2);; }
		;

factor_expr
		: '(' expr ')'									{ printf("lel14.1\n");$$ = $2; }
		| '"' text '"'									{ printf("lel14.2\n");$$ = $2; }
		| tree											{ printf("lel14.3\n");$$ = $1; }
		| NUMBER 										{ printf("lel14.4\n");$$ = mk_integer($1); }
		| NAME											{ printf("lel14.5 %s\n", $1);$$ = mk_var($1); }
		| EMIT_T '"' MOT '"' tree						{ printf("lel14.6\n");emit($5, $3); }
		;

match_expr
		: MATCH_T expr WITH filter_expr END				{ printf("lel15.1\n");$$ = mk_match($2, $4); }
		;

filter_expr
		: '|' pforests ARROW expr filter_expr			{ printf("lel16.1\n");$$ = mk_patterns($2, $4, $5); }
		| '|' pforests ARROW expr						{ printf("lel16.2\n");$$ = mk_patterns($2, $4, NULL); }
		;

pforests
		: pattern_expr pforests							{ printf("lel17.1\n");$$ = mk_pforest($1, $2); }
		| pattern_expr									{ printf("lel17.2\n");$$ = $1; }
		;

pattern_expr
		: '_'											{ printf("lel18.1\n");$$ = mk_wildcard(ANY); }
		| TAG '{' pattern_expr '}'						{ printf("lel18.2\n");$$ = mk_ptree($1, false, $3); }
		| TAG '{' '}'									{ printf("lel18.3\n");$$ = mk_ptree($1, true, NULL); }
		| '_' '{' pattern_expr '}'						{ printf("lel18.4\n");$$ = mk_anytree(false, $3); }
		| '_' '{' '}'									{ printf("lel18.5\n");$$ = mk_anytree(true, NULL); }
		| '*' '_' '*'									{ printf("lel18.6\n");$$ = mk_wildcard(ANYSTRING); }
		| '/' '_' '/'									{ printf("lel18.7\n");$$ = mk_wildcard(ANYFOREST); }
		| '-' '_' '-'									{ printf("lel18.8\n");$$ = mk_wildcard(ANYSEQ); }
		| NAME											{ printf("lel18.9\n");$$ = mk_pattern_var($1, TREEVAR); }
		| '*' NAME '*'									{ printf("lel18.10\n");$$ = mk_pattern_var($2, STRINGVAR); }
		| '/' NAME '/'									{ printf("lel18.11\n");$$ = mk_pattern_var($2, FORESTVAR); }
		| '-' NAME '-'									{ printf("lel18.12\n");$$ = mk_pattern_var($2, ANYVAR); }
		;
				
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** *****  GESTION CODE XML/HTML  ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
body
		/*: tree body										{ printf("lel19.1\n");$$ = mk_forest(false, $1, $2); }*/
		 : factor_expr body									{ $$ = mk_forest(false, $1, $2); }
		/*| tree											{ printf("lel19.2\n");$$ = $1; }*/
		| factor_expr											{ $$ = $1; }
		;


/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** **** GESTION HTML ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
tree
		: TAG '[' attributs ']' '{' body '}'		{ printf("lel20.1\n");$$ = mk_tree($1, true, false, false, $3, $6); }
		| TAG '[' attributs ']' '/'						{ printf("lel20.2\n");$$ = mk_tree($1, true, true, false, $3, NULL); }
		| TAG '{' body '}'							{ printf("lel20.3\n");$$ = mk_tree($1, true, false, false, NULL, $3); }
		| TAG '/'										{ printf("lel20.4\n");$$ = mk_tree($1, true, true, false, NULL, NULL); }
		| '{' body '}'								{ printf("lel20.5\n");$$ = $2; }
		;

attributs
		: TAG '=' '"' text '"' attributs				{ printf("lel21.1 %s\n", $1);$$ = mk_attributes(mk_var($1), $4, $6); }
		| TAG '=' '"' text '"'							{ printf("lel21.2 %s\n", $1);$$ = mk_attributes(mk_var($1), $4, NULL);}
		;
		
text
		: word_t text									{ printf("lel24.1\n");$$ = mk_forest(false, $1, $2); }
		| word_t										{ printf("lel24.2\n");$$ = $1; }
		;

word_t
		: MOT ' ' 										{ printf("lel25.1 %s\n", $1);$$ = mk_tree("text", false, false, true, NULL, mk_word($1)); }
		| MOT	 										{ printf("lel25.2 %s\n", $1);$$ = mk_tree("text", false, false, false, NULL, mk_word($1)); }
		;
%%
