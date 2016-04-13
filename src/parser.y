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

%token TAG
%token SPACE
%token SLASH
%token WORD

%start FILE

%%

FILE : FILE SPACE TREE
		| TREE
		;

TREE : TAG '[' ATTRIBUTS ']' '{' CONTENU '}'
		| TAG '[' ATTRIBUTS ']' SPACE '{' CONTENU '}'
		| TAG '[' ATTRIBUTS ']' SLASH
		| TAG '{' CONTENU '}'
		| TAG SLASH
		| '{' CONTENU '}'
		;

ATTRIBUTS : ATTRIBUTS SPACE ATTRIBUT
		| ATTRIBUT
		;

ATTRIBUT : TAG '=' '"' TEXT '"'
		;
		
CONTENU : TREE
		| SPACE '"' TEXT '"' SPACE
		| SPACE '"' TEXT '"'
		| '"' TEXT '"' SPACE
		| '"' TEXT '"'
		| %empty
		;
		
TEXT : TEXT SPACE WORD
		| WORD
		;

%%
