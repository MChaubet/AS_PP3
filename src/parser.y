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

file: 	:	file balise								{ ; }
		|	%empty									{ ; }
		;

balise  : 	label "[" attribut "]" "{" contenu "}"	{ ; }
		|	label "{" contenu  "}"					{ ; }
		|	label "[" attribut "]" SLASH			{ ; }	
		;
contenu :	balise									{ ; }
		|	texte									{ ; }
		;
texte   :

%%
//Grammaire au dessus

//Code C en dessous
