%{
	#include "main.h"
	#include "parser.tab.h"
	#include <string.h>
	
	int yylex(void);
	void yyerror(char *);
%}

%option noinput nounput

	/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
	/* ***** ***** ***** * CONSTANTES ET ETATS * ***** ***** ***** */
	/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
%x TEXT

XML [xX][mM][lL]
	/* Tags et variables */
EXP [[:alpha:]\_][[:alnum:]\_\.\']*

%%
	/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
	/* ***** ***** *****  LES INSTRUCTIONS CAML  ***** ***** ***** */
	/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
"let"											{ return LET; }
"rec"											{ return REC; }
"fun"											{ return FUN; }
"in"											{ return IN; }
"where"											{ return WHERE; }
"if"											{ return IF; }
"then"											{ return THEN; }
"else"											{ return ELSE; }
"match"											{ return MATCH; }
"with"											{ return WITH; }
"end"											{ return END; }
"emit"											{ return EMIT; }


	/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
	/* ***** ***** **** LES INSTRUCTIONS XML/HTML **** ***** ***** */
	/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
	
[[:space:]]+/\/									{ 	/* Les '/' précédés d'espaces */
													return ' '; }

[[:space:]]+									{ 	/* Supression des espaces */
													; }
	
[[:digit:]]+									{ 	/* Renvoi d'entiers */
													yylval.value = atoi(yytext); return INTEGER; }
	
({XML}{EXP}|\_)									{ 	/* '_' ou noms préfixés XML */
													/*return ERROR;*/ }
	
{EXP}/[\{\[\/\=]								{ 	/* Renvoie de TAGs */
													yylval.name = strdup(yytext); return TAG; }
	
{EXP}											{ 	/* Renvoie de variables CAML */
													yylval.name = strdup(yytext); return NAME; }
	
\"												{	/* Début d'un texte */	
													BEGIN TEXT; return yytext[0]; }
	
.												{	/* Autres caractères */
													return yytext[0];}
													
													
	/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
	/* ***** ***** ***** ** GESTION DE TEXTE *** ***** ***** ***** */
	/* ***** ***** ***** ***** ***** ***** ***** ***** ***** ***** */
	
<TEXT>\"										{ 	/* Fin d'un texte */
													BEGIN INITIAL; return yytext[0]; }

<TEXT>[[:space:]]+								{ 	/* Fusion d'espaces en un */
													return ' '; }

<TEXT>[^[:space:]]*\\\"[^[:space:]]*			{	/* Mots contenant \" */
													yylval.name = strdup(yytext); return MOT; }
	
<TEXT>[^\"[:space:]]+							{	/* Retourne un mot */
													yylval.name = strdup(yytext); return MOT; }
