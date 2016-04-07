#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "main.h"

int main (void) {
	FILE *file = fopen(argv[1], "r");
	if (file) {
	    yyin = file;
		yyparse();	
		return EXIT_SUCCESS;
	}
	return EXIT_FAILLURE;
}
