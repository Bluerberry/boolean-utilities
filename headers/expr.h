#ifndef EXPR_H
#define EXPR_H

// -----------------> Structs

typedef struct Expression {
    char key;
    char * txt;
    char * vars;
} expr_t;

// -----------------> Functions

expr_t * init_expr(char * txt);
void display_expr(expr_t * expr);
void free_expr(expr_t * expr);

#endif