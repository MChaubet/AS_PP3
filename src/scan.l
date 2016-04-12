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

	int isForest = 1;
	int accolades = 0;
	int crochets = 0;
%}

%x TEXT
%x ATTRIBUT
%x VALEUR

XML [xX][mM][lL]
MAIN [[:alnum:]_\.\']*
EXP [[:alpha:]_]{MAIN}

%%

	/* Etiquettes et attributs (Convention)
	
	 * Elles doivent commencer par une lettre ou un caractère ’_’ (mais ’_’ seul n’est pas accepté comme étiquette possible) 
	 * Elles ne doivent pas commencer par une séquence de la forme xml, XML, Xml, etc.
	 * Elles peuvent contenir des lettres, des chiffres, des apostrophes, des points, des caractères ’_’.
	 * Elles ne doivent pas contenir d’espace.
	 
	 * Le nom de l’étiquette soit immédiatement accolé (sans espace ou saut de ligne) soit à :
	 * 	Un crochet ouvrant '[' au cas où on souhaite associer une liste d'attributs au noeud
	 * 	un accolade ouvrante '{' pour écrire le contenu du noeud
	 * 	Un symbole '/' si on souhaite décrire un noeud qui ne peut avoir de contenu
	 *    (NB: foo/ représente la balise <foo/> alors que foo{} représente la balise <foo></foo>)
	 
	 * Si un nom d'étiquette est suivi d'une liste d'attributs entre crochets alors :
	 * 	Il peut y avoir des espaces et des sauts de lignes entre la fin de la déclaration des attributs et l’accolade ouvrante qui permet de décrire le contenu du noeud
	 *  s’il s’agit d’un nœud qui ne peut pas avoir de contenu, on impose que le ’/’ soit directement positionné après le crochet fermant.
	 
	 * On autorise également d’écrire une forêt entre accolades sans qu’il y ait besoin d’une balise pour ouvrir la racine
	 
	 * Les contenus textuels d’une balise sont toujours entre guillemets doubles. Les espaces et les sauts de lignes servent seulement à séparer deux mots consécutifs et ont donc peu d’importance
	 */
({XML}{EXP}|{EXP}[.^\/\[\{{MAIN}]|\_+)			{ /*TODO retourner erreur */						printf ("erreur");}
{EXP}											{ /*TODO retourner mot */							isForest=0; printf ("<tag>\n"); }
\/												{ /*TODO balise précédente vide*/					printf ("<tag/ Fermant>\n");}
\{												{ /*TODO début des fils de la balise */ 			
													if (isForest)
														{/* Creer foret*/}
													else
										 				{/* Creer balise*/ 
										 	 		 	 isForest=1; }
										 	 		printf ("débuts fils\n"); }
\}												{ /*TODO fin des fils de la balise */ 				printf ("fin fils\n");}
\[												{ /*TODO commencer ATTRIBUT*/						BEGIN ATTRIBUT; printf ("débuts attributs\n");}
\"												{ /*TODO commencer TEXT*/							BEGIN TEXT; printf ("/StartText/\n");}
<TEXT>[[:alnum:]èàùéâêîôûäëïöü]+				{ /*TODO retourner mot*/ 							printf ("mot ");}
<TEXT>\"										{ /*TODO fin TEXT */								BEGIN INITIAL; printf ("/EndText/\n");}
<ATTRIBUT>({XML}{EXP}|{EXP}[.^\={MAIN}]|\_+) 	{ /*TODO retourner erreur */						printf("erreur !!\n"); }
<ATTRIBUT>{EXP}\=								{ /*TODO retourner attribut (sauf égal à la fin)*/	BEGIN VALEUR; printf ("newAttibut\n");}
<ATTRIBUT>\]									{ /*TODO fin d'attributs */ 						BEGIN INITIAL; printf ("fin attibuts\n");}
<VALEUR>(\"[^\"]*\"|true|false|[[:digit:]]*)	{ /*TODO retourner valeur*/							BEGIN ATTRIBUT; printf ("valeur attibuts = %s\n", yytext);}
.|\n											{ /*TODO Tous les autres caractères et fin de lignes*/ }

%%

int main (void) {
	yylex();	
	return 0;
}
