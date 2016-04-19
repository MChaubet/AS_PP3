%{
	#include "main.h"
	#include "parser.tab.h"
	
	int yylex(void);
	void yyerror(char *);
%}

%option noinput nounput

%x TEXT

XML [xX][mM][lL]
INSTR ("let"|"if"|"then"|"else"|"with"|"in"|"where"|"emit"|"rec"|"fun"|"match"|"end")
/* Expression régulière des tags et variables */
EXP [[:alpha:]\_][[:alnum:]\_\.\']*

%%
	/* Les '/' précédés d'espaces */
[[:space:]]+/\/									{ printf(" "); }
	/* On supprime tous les espaces pour ne pas avoir à les gérer dans la grammaire */
[[:space:]]+									{ }
	/* Les nom de variables débutants par des variantes de 'xml', ou simplement constitués de '_' provoquent des ereurs */
({XML}{EXP}|\_)									{ /*return ERROR;*/ }
	/* Les instructions d'Ocaml */
{INSTR}/[[:space:]]								{ return INST; }
	/* Les expressions suivies de '{', '[', '/' ou '=' sont des TAGs */
{EXP}/[\{\[\/\=]								{ return TAG; }
	/* Les expressions qui ne sont pas des tags sont des noms de variables, de fonctions ou d'actions */
{EXP}											{ return NAME; }
	/* On entre en écriture de texte */
\"												{ BEGIN TEXT; ECHO; }
	/* On arrete l'écriture de texte */
<TEXT>\"										{ BEGIN INITIAL; ECHO; }
	/* On renvoie un simple espace losque l'on en détecte une suite */
<TEXT>[[:space:]]+								{ printf(" "); }
	/* On fait attention à la détection du symple double quote quand il est échappé par '\' */
<TEXT>[.^[:space:]]*\\\"[.^[:space:]]*			{ return WORD; }
	/* Toutes les suites de caractères sauf l'espace constituent un mot */
<TEXT>[.^\"[:space:]]+							{ return WORD; }
%%














