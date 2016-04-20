#ifndef MAIN_H
#define MAIN_H

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "ast.h"
#include "parser.tab.h"

int yyparse(void);

#endif
