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
}

%token TAG			// Nom de balise
%token INST			// Mot clé  OCaml
%token NAME			// Variable OCaml
%token MOT			// Mot d'un texte

/* Temporaire */
%token ACTION

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
		| INST INST NAMES '=' INST NAMES "->" BODY ';'	{ if($2 == "rec"); }
		;

NAMES : NAMES NAME										{ $$ = mk_forest(false, $1, $2); }
		| NAME											{ $$ = $1; }
		;

BODY : BODY TREE										{ $$ = mk_forest(false, $1, $2); }
		| BODY ACTION									{ $$ = mk_forest(false, $1, $2); }
		| TREE											{ $$ = $1; }
		| ACTION										{ $$ = $1; }
		;

TREE : TAG '[' ATTRIBUTS ']' '{' CONTENUS '}'			{ $$ = mk_tree($1, true, false, false, $2, $3); }
		| TAG '[' ATTRIBUTS ']' '/'						{ $$ = mk_tree($1, true, false, false, $2, NULL); }
		| TAG '{' CONTENUS '}'							{ $$ = mk_tree($1, true, false, false, NULL, $3); }
		| TAG '/'										{ $$ = mk_tree($1, true, false, false, NULL, NULL); }
		| '{' CONTENUS '}'								{ $$ = $1; }
		;

ATTRIBUTS : ATTRIBUTS TAG '=' '"' TEXT '"'				{ $$ = mk_attributes($2, $3, $1); }
		| TAG '=' '"' TEXT '"'							{ $$ = mk_attributes($1, $2, NULL); }
		;

CONTENUS : CONTENUS CONTENU								{ $$ = mk_forest(false, $1, $2); }
		| CONTENU										{ $$ = $1; }
		;
	
CONTENU : TREE											{ $$ = $1; }
		| '"' TEXT '"'									{ $$ = $1; }
		;
		
TEXT : TEXT WORD_T										{ $$ = mk_forest(false, $1, $2); }
		| WORD_T										{ $$ = $1; }
		;

WORD_T : MOT ' ' 										{ $$ = mk_tree("text", false, false, true, NULL, mk_word(yylval)); }
		| MOT	 										{ $$ = mk_tree("text", false, false, false, NULL, mk_word(yylval)); }
		;

%%
