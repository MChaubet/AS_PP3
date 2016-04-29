#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ast.h"

int indentation=0;

void ajouter_body (struct ast * t, struct ast * body) {
	while (t != NULL)
			t = t->body;
	t = body;
}

//TODO Modifier pour juste récupérer la chaine de caractère qui est
//TODO retourner par la fonction to_string pour la copier dans le fichier
void emit(struct ast * t, char * filename){
    int stdoutCopy = dup(1);
    printf("Tentative de creation de '%s'\n", filename );
    int file = creat(filename, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if(file){
        if(dup2(file, 1)){
            to_string(t);
            printf("\n");
            dup2(stdoutCopy, 1);
            printf("Ecriture réussi\n");
        } else {
            printf("Erreur de redirection du flux\n");
        }
    } else {
        printf("Erreur à la creation du fichier\n");
    }
}

//TODO Modifier le prototype pour renvoyer un certain nombre de \t
static void auto_indent(void){
    int i;
    for(i=0; i<indentation;i++){
        printf("\t");
    }
}

//TODO Remplacer le prototype de la fonction pour qu'elle retourne un string
//TODO Pour pouvoir ensuite éventuellement évaluer les fonctions OCaml
//TODO Rajouter les autres types du enum
//TODO Faire éventuellement des fonctions annexes pour l'évaluation
void to_string(struct ast * t){
    switch (t->type) {
        case FOREST:
            if(t->node->forest->head != NULL)
                to_string(t->node->forest->head);
            if(t->node->forest->tail != NULL)
                to_string(t->node->forest->tail);
            break;

        case TREE:
            if(strcmp("text", t->node->tree->label) !=0){
		        printf("\n");
		        auto_indent();
		        printf("<%s", t->node->tree->label);
		        indentation++;
		        struct attributes * att = t->node->tree->attributes;
		        while(att != NULL){
		            printf(" %s='", att->key->node->str);
		            to_string(att->value);
		            printf("'");
		            att = att->next;
		        }
		        if(t->node->tree->nullary == false){
		            printf(">\n");
		            auto_indent();
		            to_string(t->node->tree->daughters);

		            if(t->node->tree->space == true){
		                printf(" ");
		            }
		            indentation--;
		            printf("\n");
		            auto_indent();
		            printf("</%s>\n", t->node->tree->label);
		            auto_indent();
		        } else {
		            indentation--;
		            printf("/>\n");
		        }
		    } else {
		        to_string(t->node->tree->daughters);
		    }
            break;
            
        case WORD:
            printf("%s",t->node->str);
            break;
            
        default:
            printf("Type non reconnu\n");
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
    e->node->chemin = malloc(sizeof(*e->node->chemin));
    e->node->chemin = chemin;
    return e;
}
struct ast * mk_app(struct ast * fun, struct ast * arg){
    struct ast * e = mk_node();
    e->node->app = malloc(sizeof(*e->node->app));
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
}
struct attributes * mk_attributes(struct ast * key, struct ast * value, struct attributes * next){
    struct attributes * e = malloc(sizeof(struct attributes));
    e->key = key;
    e->value = value;
    e->next = next;
    return e;
}
struct ast * mk_tree(char * label, bool is_value, bool nullary, bool space,
                     struct attributes * att, struct ast * daughters){
    struct ast * e = mk_node();
    e->type = TREE;
    e->node->tree = malloc(sizeof(*e->node->tree));
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
    e->node->forest = malloc(sizeof(*e->node->forest));
    e->node->forest->is_value = is_value;
    e->node->forest->head=head;
    e->node->forest->tail=tail;
    return e;
}
struct ast * mk_fun(char * id, struct ast * body){
    struct ast * e = mk_node();
    e->type = FUN;
    e->node->fun = malloc(sizeof(*e->node->fun));
    e->node->fun->id = id;
    e->node->fun->body=body;
    return e;
}
struct ast * mk_match(struct ast * ast, struct patterns * patterns){
    struct ast * e = mk_node();
    e->type = MATCH;
    e->node->match = malloc(sizeof(*e->node->match));
    e->node->match->ast = ast;
    e->node->match->patterns=patterns;
    return e;
}
struct ast * mk_cond(struct ast * cond, struct ast * then_br, struct ast * else_br){
    struct ast * e = mk_node();
    e->type = COND;
    e->node->cond = malloc(sizeof(*e->node->cond));
    e->node->cond->cond = cond;
    e->node->cond->then_br=then_br;
    e->node->cond->else_br=else_br;
    return e;
}
struct ast * mk_declrec(char * id, struct ast * body){
    struct ast * e = mk_node();
    e->type = DECLREC;
    e->node->fun = malloc(sizeof(*e->node->fun));
    e->node->fun->id = id;
    e->node->fun->body=body;
    return e;
}
