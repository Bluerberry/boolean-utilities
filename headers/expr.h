#ifndef EXPR_H
#define EXPR_H

// -----------------> Structs

typedef struct Expression {
    char key;
    char * txt;
} expr_t;

// -----------------> Functions

expr_t * init_expr(char * txt);

#endif