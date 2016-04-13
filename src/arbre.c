#include "arbre.h"

typedef struct tree * tree;
typedef struct attributes * attributes;


tree createTree(char * label) {
	tree t = malloc(sizeof(*t));
	t->label = strdup(label);
	t->nullary = TRUE;
	t->space = FALSE;
	enum type my_type = TREE;
	t->tp = my_type;
	t->attr = NULL;
	t->daughter = NULL;
	t->next = NULL;
	return t;
}

tree createWord(char * label, bool space) {
	tree t = malloc(sizeof(*t));
	t->label = strdup(label);
	t->nullary = TRUE;
	t->space = TRUE;
	enum type my_type = WORD;
	t->tp = my_type;
	t->attr = NULL;
	t->daughter = NULL;
	t->next = NULL;
	return t;
}

attributes createAttribute(char * key, char * value) {
	attributes a = malloc(sizeof(*a));
	a->key = strdup(key);
	a->value = strdup(value);
	a->next = NULL;
	return a;
}

void displayTree(tree t){
	//Affichage de lui meme
	//Voir ses fils
	//Voir ses freres avec recurcivite
}
