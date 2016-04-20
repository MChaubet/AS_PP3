%{
	#include "main.h"

	int yylex(void);
	void yyerror(char *);
%}

%output "parser.tab.c"

%token TAG			// Nom de balise
%token INST			// Mot clé  OCaml
%token NAME			// Variable OCaml
%token WORD			// Mot d'un texte
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

FILE : DECLS BODY										{ ; }
		| BODY											{ ; }
		;

DECLS : DECLS DECL										{ ; }
		| DECL											{ ; }
		;

DECL : INST NAMES '=' BODY ';'
		| INST INST NAMES '=' BODY ';'
		| INST NAMES '=' INST NAMES "->" BODY ';'
		| INST INST NAMES '=' INST NAMES "->" BODY ';' 
		;

NAMES : NAMES NAME
		| NAME
		;

BODY : BODY TREE										{ ; }
		| BODY ACTION									{ ; }
		| TREE											{ ; }
		| ACTION										{ ; }
		;

TREE : TAG '[' ATTRIBUTS ']' '{' CONTENUS '}'			{ ; }
		| TAG '[' ATTRIBUTS ']' '/'						{ ; }
		| TAG '{' CONTENUS '}'							{ ; }
		| TAG '/'										{ ; }
		| '{' CONTENUS '}'								{ ; }
		;

ATTRIBUTS : ATTRIBUTS ATTRIBUT							{ ; }
		| ATTRIBUT										{ ; }
		;

ATTRIBUT : TAG '=' '"' TEXT '"'							{ ; }
		;

CONTENUS : CONTENUS CONTENU								{ ; }
		| CONTENU										{ ; }
		;
	
CONTENU : TREE											{ ; }
		| '"' TEXT '"'									{ ; }
		;
		
TEXT : TEXT WORD_T										{ ; }
		| WORD_T										{ ; }
		;

WORD_T : WORD ' ' 										{ $$ = mk_tree("text", FALSE, FALSE, TRUE, NULL, mk_word($1)); }
		| WORD	 										{ $$ = mk_tree("text", FALSE, FALSE, FALSE, NULL, mk_word($1)); }
		;

%%
