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
%token TEXT
%token EOF;		//End Of File

%start arbre

%%

arbre: arbre EOF		{}
	|  EOF				{}
	;

	

%%
//Grammaire au dessus

//Code C en dessous
