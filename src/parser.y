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

/* TODO Les tokens que l'on devrait avoir */ 
%token ERROR
%token TAG
%token INST
%token VAR
%token WORD

/* TODO Les tokens à supprimer au final */
%token KEY
%token SLASH

%start FILE

%%

FILE : FILE TREE										{ ; }
		| TREE											{ $$ = $1; }
		;

TREE : TAG '[' ATTRIBUTS ']' '{' CONTENU '}'			{ ; }
		| TAG '[' ATTRIBUTS ']' SLASH					{ ; }
		| TAG '{' CONTENU '}'							{ ; }
		| TAG SLASH										{ ; }
		| '{' CONTENU '}'								{ ; }
		;

ATTRIBUTS : ATTRIBUTS ATTRIBUT							{ ; }
		| ATTRIBUT										{ $$ = $1; }
		;

ATTRIBUT : KEY '=' '"' TEXT '"'							{ /*$$ = createAttribute($1, $4)*/; }
		;
		
CONTENU : TREE											{ $$ = $1; }
		| '"' TEXT '"'									{ /*$$ = createTree($2)*/; }
		| %empty										{ ; }
		;
		
TEXT : TEXT SPACE WORD									{ ; }
		| WORD											{ $$ = $1; }
		;

%%
