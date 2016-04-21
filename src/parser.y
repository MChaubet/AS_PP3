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
}

%token < name > TAG		// Nom de balise
%token < name > INST	// Mot clé  OCaml
%token < name > NAME	// Variable OCaml
%token < name > MOT		// Mot d'un texte

	/* Temporaire */
%token < ast > ACTION

%type < ast > FILE DECLS DECL NAMES BODY TREE CONTENUS CONTENU TEXT WORD_T
%type < attributes > ATTRIBUTS

%start FILE

%%
/*
Une variable peut etre implémenté par "let var = contenu;"
CONST --> INST NAME '='  ';'

En revanche une fonction peut etre implémenté par 
	"let f var1 var2 = contenu;"
	"let f = fun var1 var2 -> contenu;"
	"let f var1 var2 = func var1 var2 -> contenu;"
	"let rec f var1 var2 = func var1 var2 -> contenu;"
*/

//TODO Voir si faire une foret avec les declarations et le body
FILE : DECLS BODY										{ $$ = mk_forest(false, $1, $2); }
		| BODY											{ $$ = $1; }
		;

DECLS : DECL DECLS										{ $$ = mk_forest(false, $1, $2); }
		| DECL											{ $$ = $1; }
		;

DECL : INST NAMES '=' BODY ';'							{ if( $2->type == FOREST )
															$$ = mk_app(mk_fun($2->node->forest->head->node->str, $4), $2->node->forest->tail); }
		| INST INST NAMES '=' BODY ';'					{ ; }
		| INST NAMES '=' INST NAMES "->" BODY ';'		{ ; }
		| INST INST NAMES '=' INST NAMES "->" BODY ';'	{ ; }
		;

//TODO Voir pour la possibilite d'avoir plusieurs noms pour argument de fonction
//TODO Foret de noms n'est pas la meilleur idee
NAMES : NAME NAMES										{ $$ = mk_forest(false, mk_var($1), $2); }
		| NAME											{ $$ = mk_var($1); }
		;

BODY : TREE BODY										{ $$ = mk_forest(false, $1, $2); }
		| ACTION BODY									{ $$ = mk_forest(false, $1, $2); }
		| TREE											{ $$ = $1; }
		| ACTION										{ $$ = $1; }
		;

TREE : TAG '[' ATTRIBUTS ']' '{' CONTENUS '}'			{ $$ = mk_tree($1, true, false, false, $3, $6); }
		| TAG '[' ATTRIBUTS ']' '/'						{ $$ = mk_tree($1, true, true, false, $3, NULL); }
		| TAG '{' CONTENUS '}'							{ $$ = mk_tree($1, true, false, false, NULL, $3); }
		| TAG '/'										{ $$ = mk_tree($1, true, true, false, NULL, NULL); }
		| '{' CONTENUS '}'								{ $$ = $2; }
		;

ATTRIBUTS : TAG '=' '"' TEXT '"' ATTRIBUTS				{ $$ = mk_attributes(mk_var($1), $4, $6); }
		| TAG '=' '"' TEXT '"'							{ $$ = mk_attributes(mk_var($1), $4, NULL); }
		;

CONTENUS : CONTENU CONTENUS								{ $$ = mk_forest(false, $1, $2); }
		| CONTENU										{ $$ = $1; }
		;
	
CONTENU : TREE											{ $$ = $1; }
		| '"' TEXT '"'									{ $$ = $2; }
		;
		
TEXT : WORD_T TEXT										{ $$ = mk_forest(false, $1, $2); }
		| WORD_T										{ $$ = $1; }
		;

WORD_T : MOT ' ' 										{ $$ = mk_tree("text", false, false, true, NULL, mk_word($1)); }
		| MOT	 										{ $$ = mk_tree("text", false, false, false, NULL, mk_word($1)); }
		;

%%
