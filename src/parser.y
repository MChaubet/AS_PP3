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
%type < ast > contenus
%type < ast > text
%type < ast > word_t


/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** *** DEBUT GRAMMAIRE *** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
%start file
%%

file
		: declarations_globales body					{ $$ = mk_forest(false, $1, $2); }
		| body											{ $$ = $1; emit($$, "sortie.html");}
		;

/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** *** GESTION DES DECLARATIONS DE TOUS TYPES **** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
declarations_globales
		: declaration ';' declarations_globales			{ $$ = mk_forest(false, $1, $3);}
		| declaration ';'								{ $$ = $1; }
		;

declaration
		: LET names '=' functions 						{ ajouter_body($2->node->fun->body, $4); $$ = $2; }
		| LET REC names '=' functions 					{ ajouter_body($3->node->fun->body, $5); $$ = $3; }
		;

names
		: NAME names									{ $$ = mk_fun($1, $2); }
		| NAME											{ $$ = mk_fun($1, NULL); }
		;

functions
		: FUNC names ARROW functions					{ ajouter_body($2->node->fun->body, $4); $$ = $2; }
		| expr											{ $$ = $1; }
		;
		
declaration_locale	/* Expression pour les déclarations IN et WHERE */
		: LET NAME '=' factor_expr IN expr				{ $$ = mk_app(mk_fun($2, $6), $4); }
		| LET REC NAME '=' factor_expr IN expr			{ $$ = mk_app(mk_fun($3, $7), mk_declrec($3, $5)); }
		| factor_expr WHERE NAME '=' expr				{ $$ = mk_app(mk_fun($3, $1), $5); }
		| factor_expr WHERE REC NAME '=' expr			{ $$ = mk_app(mk_fun($4, $1), mk_declrec($4, $6)); }
		;

/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ** GESTION DES EXPRESSIONS CAML *** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
expr	/* Expressions générales */
		: conditional_expr								{ $$ = $1; }
		| declaration_locale							{ $$ = $1; }
		;

conditional_expr
		: IF logical_expr THEN expr ELSE expr			{ $$ = mk_cond($2, $4, $6); }
		| logical_expr									{ $$ = $1; }
		;

logical_expr
		: logical_expr OU relational_expr				{ $$ = mk_app(mk_app(mk_binop(OR), $1), $3); }
		| logical_expr ET relational_expr				{ $$ = mk_app(mk_app(mk_binop(AND), $1), $3); }
		| relational_expr								{ $$ = $1; }
		;
		
relational_expr 
		: relational_expr INF		additive_expr		{ $$ = mk_app(mk_app(mk_binop(LE), $1), $3); }
		| relational_expr SUP		additive_expr		{ $$ = mk_app(mk_app(mk_binop(LEQ), $1), $3); }
		| relational_expr SUP_EQ	additive_expr		{ $$ = mk_app(mk_app(mk_binop(GE), $1), $3); }
		| relational_expr INF_EQ	additive_expr		{ $$ = mk_app(mk_app(mk_binop(GEQ), $1), $3); }
		| relational_expr EQ_T		additive_expr		{ $$ = mk_app(mk_app(mk_binop(EQ), $1), $3); }
		| relational_expr NOT_EQ	additive_expr		{ $$ = mk_app(mk_app(mk_binop(NEQ), $1), $3); }
		| additive_expr									{ $$ = $1; }
		;

additive_expr
		: additive_expr '+' multiplicative_expr			{ $$ = mk_app(mk_app(mk_binop(PLUS), $1), $3); }
		| additive_expr '-' multiplicative_expr			{ $$ = mk_app(mk_app(mk_binop(MINUS), $1), $3); }
		| multiplicative_expr							{ $$ = $1; }
		;

multiplicative_expr
		: multiplicative_expr '*'  negative_expr		{ $$ = mk_app(mk_app(mk_binop(MULT), $1), $3); }
		| multiplicative_expr '/' negative_expr			{ $$ = mk_app(mk_app(mk_binop(DIV), $1), $3); }
		| negative_expr									{ $$ = $1; }
		;

negative_expr
		: factor_expr									{ $$ = $1; }
		| '!' factor_expr								{ $$ = mk_app(mk_unaryop(NOT), $2);; }
		;

factor_expr
		: '(' expr ')'									{ $$ = $2; }
		| '"' text '"'									{ $$ = $2; }
		| '"' ' ' text '"'								{ $$ = mk_forest(false, mk_tree("text", false, false, true, NULL, mk_word("")), $3); }
		| tree											{ $$ = $1; }
		| NUMBER 										{ $$ = mk_integer($1); }
		| NAME											{ $$ = mk_var($1); }
		| EMIT_T '"' MOT '"' tree						{ emit($5, $3); }
		| match_expr									{ $$ = $1; }
		;

match_expr	/* Expression du match*/
		: MATCH_T factor_expr WITH filter_expr END		{ $$ = mk_match($2, $4); }
		;

filter_expr	/* Expressions filtres pour le match */
		: '|' pforests ARROW expr filter_expr			{ $$ = mk_patterns($2, $4, $5); }
		| '|' pforests ARROW expr						{ $$ = mk_patterns($2, $4, NULL); }
		;

pforests	/* Pattern de forets pour le match */
		: pattern_expr pforests							{ $$ = mk_pforest($1, $2); }
		| pattern_expr									{ $$ = $1; }
		;

pattern_expr	/* Expressions possibles pour le pattern de forets */
		: TAG '{' pattern_expr '}'						{ $$ = mk_ptree($1, false, $3); }
		| TAG '{' '}'									{ $$ = mk_ptree($1, true, NULL); }
		| '_' '{' pattern_expr '}'						{ $$ = mk_anytree(false, $3); }
		| '_' '{' '}'									{ $$ = mk_anytree(true, NULL); }
		| '_'											{ $$ = mk_wildcard(ANY); }
		| '*' '_' '*'									{ $$ = mk_wildcard(ANYSTRING); }
		| '/' '_' '/'									{ $$ = mk_wildcard(ANYFOREST); }
		| '-' '_' '-'									{ $$ = mk_wildcard(ANYSEQ); }
		| NAME											{ $$ = mk_pattern_var($1, TREEVAR); }
		| '*' NAME '*'									{ $$ = mk_pattern_var($2, STRINGVAR); }
		| '/' NAME '/'									{ $$ = mk_pattern_var($2, FORESTVAR); }
		| '-' NAME '-'									{ $$ = mk_pattern_var($2, ANYVAR); }
		;
				
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ** GESTION CODE HTML ** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
body
		: factor_expr body								{ $$ = mk_forest(false, $1, $2); }
		| factor_expr									{ $$ = $1; }
		;


/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
/* ***** ***** ***** **** GESTION HTML ***** ***** ***** ***** */
/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
tree
		: TAG '[' attributs ']' '{' contenus '}'		{ $$ = mk_tree($1, true, false, false, $3, $6); }
		| TAG '[' attributs ']' '/'						{ $$ = mk_tree($1, true, true, false, $3, NULL); }
		| TAG '{' contenus '}'							{ $$ = mk_tree($1, true, false, false, NULL, $3); }
		| TAG '/'										{ $$ = mk_tree($1, true, true, false, NULL, NULL); }
		| '{' contenus '}'								{ $$ = $2; }
		;

attributs
		: TAG '=' '"' text '"' attributs				{ $$ = mk_attributes(mk_var($1), $4, $6); }
		| TAG '=' '"' text '"'							{ $$ = mk_attributes(mk_var($1), $4, NULL);}
		;

contenus
		: expr ',' contenus								{ $$ = mk_forest(false, $1, $3); }
		| expr ','										{ $$ = mk_forest(false, $1, NULL); }
		| expr contenus									{ $$ = mk_forest(false, $1, $2); }
		| expr											{ $$ = $1; }
		;

text
		: word_t text									{ $$ = mk_forest(false, $1, $2); }
		| word_t										{ $$ = $1; }
		;

word_t
		: MOT ' ' 										{ $$ = mk_tree("text", false, false, true, NULL, mk_word($1)); }
		| MOT	 										{ $$ = mk_tree("text", false, false, false, NULL, mk_word($1)); }
		;
%%
