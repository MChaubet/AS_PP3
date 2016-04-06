#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROMPT "$$$ "

int yyparse(void);

struct variable {
	int value;
	char *name;
	struct variable *next;
};
struct variable *first, *last;

struct variable * new_var(char *);
struct variable *lookup(char *);
void assign(char *, int );

