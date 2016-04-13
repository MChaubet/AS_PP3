%{
	#include <assert.h>
	#include <stdbool.h>
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <unistd.h>

	#include "parser.tab.h"
%}

%x TEXT

XML [xX][mM][lL]
EXP [[:alpha:]\_][[:alnum:]\_\.\']*

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
({XML}{EXP}|\_)									{ printf("erreur 1 !!\n"); }
{EXP}											{ return TAG; }
\/												{ return SLASH; }
[[:space:]]+									{ return SPACE; }
\"												{ BEGIN TEXT; ECHO; }
<TEXT>\"										{ BEGIN INITIAL; ECHO; }
<TEXT>[[:space:]]+								{ return SPACE; }
<TEXT>[.^[:space:]]*\\\"[.^[:space:]]*			{ return WORD; }
<TEXT>[.^\"[:space:]]+							{ return WORD; }
%%
