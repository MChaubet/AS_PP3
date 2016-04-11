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
%token SLASH
%token TEXT
%token EOF		//End Of File

%start file

%%

FILE : FILE TREE EOF								{ ; }
		|	TREE									{ ; }
		|	%empty									{ ; }
			;

TREE : TEXT "[" ATTRIBUTS "]" "{" CONTENU "}"		{ ; }
		|	TEXT "{" CONTENU   "}"					{ ; }
		|	TEXT "[" ATTRIBUTS "]" SLASH			{ ; }	
		;

ATTRIBUT : ATTRIBUT SPACE ATTRIBUT
		| WORD '=' '"' WORD '"'
		;
		
CONTENU : 
		|	
		;
		
TEXT : 
		|
		;

%%
//Grammaire au dessus

//Code C en dessous
