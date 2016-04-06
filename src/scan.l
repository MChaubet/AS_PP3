%{
	#include <assert.h>
	#include <stdbool.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>

	#include "parser.tab.h"
	#include "main.h"

	int yylex(void);
	void yyerror(char *);
%}

%option nounput noinput

%x TEXTE

%%

[[:alpha:]_]+[[:alnum:]_]*{			{ return TAG; }

<BALISE>	"\""					{ BEGIN TEXTE; }
<TEXTE>		

%%
//Regles au dessus

//Code C en dessous
