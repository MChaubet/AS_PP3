#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "main.h"

struct variable * new_var(char *name) {

	struct variable * v = malloc(sizeof(struct variable));

	v->name = strdup(name);
	v->value = 0;
	v->next = NULL;

	if (first == NULL)
		first = last = v;
	else {
		last->next = v;
		last = v;
	}
	return v;
}

struct variable *lookup(char *name) {
	
	struct variable *p = first;
	while (p != NULL) {	
		if (strcmp(p->name, name) == 0)
			return p;
		p = p->next;
	}
	return new_var(name);
}

void assign(char *name, int value) {
	struct variable * v = lookup(name);
	v->value = value;
}

int main (void) {
	printf ("%s", PROMPT);
	fflush(stdout);
	yyparse();
	return EXIT_SUCCESS;
}
