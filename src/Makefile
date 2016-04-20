LEX		=flex
YACC	=bison -d -v
YFLAGS	=-d -v -t
LDLIBS	=-lfl  -ly -lm
CC      =gcc
CFLAGS	=-g -pedantic -Wall -Wextra -Wshadow -Wpointer-arith -Wcast-qual -Wstrict-prototypes -Wmissing-prototypes

all : app.out

app.out: parser.tab.c lex.yy.c main.c ast.c
	$(CC) $(CFLAGS) -o $@ $^ $(LDLIBS)

parser.tab.c: parser.y
	$(YACC) -o $@ $<
lex.yy.c: scan.l
	$(LEX)  -o $@ $<
