%{
	#include <assert.h>
	#include <stdbool.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>
	#include <math.h>

	#include "main.h"

	int yylex(void);
	void yyerror(char *);
%}

%output "parser.tab.c"

%token TAG			// Nom de balise
%token INST			// Mot clé  OCaml
%token NAME			// Variable OCaml
%token WORD			// Mot d'un texte

%start FILE

%%
/*
IDEES DE NOUVELLE REGLE :

FILE --> CONST CORPS

CORPS --> INST CORPS
CORPS --> TREE CORPS
CORPS --> EPSILON


Une variable peut etre implémenté par "let var = contenu;"
CONST --> INST NAME '='  ';'

En revanche une fonction peut etre implémenté par 
	"let f var1 var2 = contenu;"
	"let f = fun var1 var2 -> contenu;"
	"let f var1 var2 = func var1 var2 -> contenu;"
	"let rec f var1 var2 = func var1 var2 -> contenu;"
*/

// Rajout de DECLS dans FILE, de facon a avoir toutes les occurrences
// de DECLS avant les toutes les occurrences de TREES
FILE : DECLS TREES										{ ; }
		| TREES											{ $$ = $1; }
		;

DECLS : DECLS DECL										{ ; }
		| DECL											{ ; }
		;

DECL : INST NAMES '=' /*CONTENU_OCAML*/ ';'
		| INST INST NAMES '=' /*CONTENU_OCAML*/ ';'
		| INST NAMES '=' INST NAMES '-' '>' /*CONTENU_OCAML*/ ';'
		| INST INST NAMES = INST NAMES '-' '>' /*CONTENU_OCAML*/ ';' 
		;

NAMES : NAMES NAME
		| NAME
		;

TREES : TREES TREE										{ ; }
		| TREE											{ ; }
		;

TREE : TAG '[' ATTRIBUTS ']' '{' CONTENUS '}'			{ ; }
		| TAG '[' ATTRIBUTS ']' '/'						{ ; }
		| TAG '{' CONTENUS '}'							{ ; }
		| TAG '/'										{ ; }
		| '{' CONTENUS '}'								{ ; }
		;

ATTRIBUTS : ATTRIBUTS ATTRIBUT							{ ; }
		| ATTRIBUT										{ $$ = $1; }
		;

ATTRIBUT : TAG '=' '"' TEXT '"'							{ /*$$ = createAttribute($1, $4)*/; }
		;

CONTENUS : CONTENUS CONTENU								{ ; }
		| CONTENU										{ $$ = $1; }
		;
	
CONTENU : TREE											{ $$ = $1; }
			/* Possibilite d'avoir des variables locales pour des balises */
		| '"' TEXT '"'									{ /*$$ = createTree($2)*/; }
		;
		
TEXT : TEXT WORD_T										{ ; }
		| WORD_T										{ $$ = $1; }
		;

WORD_T : WORD ' ' 										{ /*Creation de mot avec espace*/; }
		| WORD	 										{ /*Creation de mot sans espace*/; }
		;

%%
