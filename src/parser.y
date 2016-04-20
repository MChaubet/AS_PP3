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
}

%token < value > TAG	// Nom de balise
%token < value > INST	// Mot clé  OCaml
%token < value > NAME	// Variable OCaml
%token < value > MOT	// Mot d'un texte

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

FILE : DECLS BODY										{ $$ = mk_forest(false, $1, $2); }
		| BODY											{ $$ = $1; }
		;

DECLS : DECL DECLS										{ $$ = mk_forest(false, $1, $2); }
		| DECL											{ $$ = $1; }
		;

DECL : INST NAMES '=' BODY ';'							{ ; }
		| INST INST NAMES '=' BODY ';'					{ ; }
		| INST NAMES '=' INST NAMES "->" BODY ';'		{ ; }
		| INST INST NAMES '=' INST NAMES "->" BODY ';'	{ ; }
		;

NAMES : NAME NAMES										{ $$ = mk_forest(false, $1, $2); }
		| NAME											{ $$ = $1; }
		;

BODY : TREE BODY										{ $$ = mk_forest(false, $1, $2); }
		| ACTION BODY									{ $$ = mk_forest(false, $1, $2); }
		| TREE											{ $$ = $1; }
		| ACTION										{ $$ = $1; }
		;

TREE : TAG '[' ATTRIBUTS ']' '{' CONTENUS '}'			{ $$ = mk_tree($1, true, false, false, $3, $6); }
		| TAG '[' ATTRIBUTS ']' '/'						{ $$ = mk_tree($1, true, false, false, $3, NULL); }
		| TAG '{' CONTENUS '}'							{ $$ = mk_tree($1, true, false, false, NULL, $3); }
		| TAG '/'										{ $$ = mk_tree($1, true, false, false, NULL, NULL); }
		| '{' CONTENUS '}'								{ $$ = $2; }
		;

ATTRIBUTS : ATTRIBUTS TAG '=' '"' TEXT '"'				{ $$ = mk_attributes($2, $5, $1); }
		| TAG '=' '"' TEXT '"'							{ $$ = mk_attributes($1, $4, NULL); }
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
