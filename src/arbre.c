#include "arbre.h"

typedef struct tree * tree;
typedef struct attributes * attributes;



tree createTree(char * label) {
	tree t = malloc(sizeof(*t));
	t->label = strdup(label);
	t->nullary = TRUE;
	t->space = FALSE;
	t->tp = TREE;
	t->attr = NULL;
	t->daughter = NULL;
	t->next = NULL;
	return t;
}

tree createWord(char * label, bool space) {
	tree t = malloc(sizeof(*t));
	t->label = strdup(label);
	t->nullary = TRUE;
	t->space = space;
	t->tp = WORD;
	t->attr = NULL;
	t->daughter = NULL;
	t->next = NULL;
	return t;
}

tree createBrotherTree(char * label, tree brother){
	tree t = createTree(label);
	t->next = &brother;
	return t;
}

tree createBrotherWord(char * label, bool space, tree brother){
	tree t = createWord(label, space);
	t->next = &brother;
}

attributes createAttribute(char * key, char * value) {
	attributes a = malloc(sizeof(*a));
	a->key = strdup(key);
	a->value = strdup(value);
	a->next = NULL;
	return a;
}
attributes createBrotherAttribute(char * key, char * value, attributes brother){
	attributes a = createAttribute(key, value);
	a->next = &brother;
	return a;
}

void displayTree(tree t){
	printf("rien pour l'instant \n");
}
