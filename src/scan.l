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

	int accolades = 0;
	int crochets = 0;
%}

%x TEXT
%x ATTRIBUT
%x VALEUR

%%
[[:alpha:]_][[:alnum:]_]*			{ /*TODO retourner mot */							printf ("<tag>\n"); }
\{									{ /*TODO début des fils de la balise */ 			printf ("débuts fils\n"); }
\}									{ /*TODO fin des fils de la balise */ 				printf ("fin fils\n");}
\[									{ /*TODO commencer ATTRIBUT*/						BEGIN ATTRIBUT; printf ("débuts attributs\n");}
\"									{ /*TODO commencer TEXT*/							BEGIN TEXT; printf ("/StartText/\n");}
<TEXT>[[:alnum:]èàùéâêîôûäëïöü]+	{ /*TODO retourner mot*/ 							printf ("mot ");}
<TEXT>\"							{ /*TODO fin TEXT */								BEGIN INITIAL; printf ("/EndText/\n");}
<ATTRIBUT>[[:alnum:]]+=				{ /*TODO retourner attribut (sauf égal à la fin)*/	BEGIN VALEUR; printf ("newAttibut\n");}
<ATTRIBUT>\]						{ /*TODO fin d'attributs */ 						BEGIN INITIAL; printf ("fin attibuts\n");}
<VALEUR>(\"[^\"]*\"|true|false|[[:digit:]]*)	{ /*TODO retourner valeur*/	BEGIN ATTRIBUT; printf ("valeur attibuts = %s\n", yytext);}
.|\n								{;}
%%

int main (void) {
	yylex();	
	return 0;
}
