#include <stdlib.h>
#include "ast.h"

void to_string(ast * t){
    switch (t->type) {
        case FOREST:
            if(t->node->forest->head != NULL)
                to_string(t->node->forest->head);
            if(t->node->forest->tail != NULL)
                to_string(t->node->forest->tail);
            break;

        case TREE:
            printf("<%s ", t->node->tree->label);
            struct attributes * att = t->node->tree->attributes;
            while(att != NULL){
                printf("%s='%s' ", att->key->node->str, att->value->node->str);
                att = att->next;
            }
            if(t->node->tree->nullary != false){
                printf(">");
                to_string(t->node->daughters);
                if(t->node->tree->space == true){
                    printf(" ");
                }
                printf("</%s>", t->node->tree->label);
            } else {
                printf("/>");
            }
            break;
        case WORD:
            printf("%s\n",t->node->str);
            break;
        default:
            printf("Type non reconnu\n", );
    }
}
struct ast * mk_node(void){
    struct ast *e = malloc(sizeof(struct ast));
    e->node = malloc(sizeof(union node));
    return e;
}
struct ast * mk_integer(int n){
    struct ast * e = mk_node();
    e->type = INTEGER;
    e->node->num = n;
    return e;
}
struct ast * mk_binop(enum binop binop){
    struct ast * e = mk_node();
    e->type = BINOP;
    e->node->binop = binop;
    return e;
}
struct ast * mk_unaryop(enum unaryop unaryop){
    struct ast * e = mk_node();
    e->type = UNARYOP;
    e->node->unaryop = unaryop;
    return e;
}
struct ast * mk_var(char * var){
    struct ast * e = mk_node();
    e->type = VAR;
    e->node->str = var;
    return e;
}
struct ast * mk_import(struct path * chemin){
    struct ast * e = mk_node();
    e->type = IMPORT;
    e->node->chemin = chemin;
    return e;
}
struct ast * mk_app(struct ast * fun, struct ast * arg){
    struct ast * e = mk_node();
    e->type = APP;
    e->node->app->fun = fun;
    e->node->app->arg = arg;
    return e;
}
struct ast * mk_word(char * str){
    struct ast * e = mk_node();
    e->type = WORD;
    e->node->str = str;
    return e;
};
struct attributes * mk_attributes(ast * key, ast * value, attributes * next){
    struct attributes * e = malloc(sizeo(struct attributes));
    e->key = key;
    e->value = value;
    e->next = next;
    return e;
}
struct ast * mk_tree(char * label, bool is_value, bool nullary, bool space,
                     struct attributes * att, struct ast * daughters){
    struct ast * e = mk_node();
    e->type = TREE;
    e->node->tree->label = label;
    e->node->tree->is_value=is_value;
    e->node->tree->nullary=nullary;
    e->node->tree->space=space;
    e->node->tree->attributes=att;
    e->node->tree->daughters=daughters;
    return e;
}
struct ast * mk_forest(bool is_value, struct ast * head, struct ast * tail){
    struct ast * e = mk_node();
    e->type = FOREST;
    e->node->forest->is_value = is_value;
    e->node->forest->head=head;
    e->node->forest->tail=tail;
    return e;
}
struct ast * mk_fun(char * id, struct ast * body){
    struct ast * e = mk_node();
    e->type = FUN;
    e->node->fun->id = id;
    e->node->fun->body=body;
    return e;
}
struct ast * mk_match(struct ast * ast, struct patterns * patterns){
    struct ast * e = mk_node();
    e->type = MATCH;
    e->node->match->ast = ast;
    e->node->match->patterns=patterns;
    return e;
}
struct ast * mk_cond(struct ast * cond, struct ast * then_br, struct ast * else_br){
    struct ast * e = mk_node();
    e->type = COND;
    e->node->cond->cond = cond;
    e->node->cond->then_br=then_br;
    e->node->cond->else_br=else_br;
    return e;
}
struct ast * mk_declrec(char * id, struct ast * body){
    struct ast * e = mk_node();
    e->type = DECLREC;
    e->node->fun->id = id;
    e->node->fun->body=body;
    return e;
}
