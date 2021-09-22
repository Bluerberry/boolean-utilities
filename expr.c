// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>

#include "headers/expr.h"

// -----------------> Functions

// Creates a new globals list
expr_t * init_expr(char * txt) {

    // Allocate globals
    expr_t * expr = malloc(sizeof(expr_t));
    if (expr == NULL) {
        printf("Error: Insufficient memory to allocate 'expr'\n");
        exit(-1);
    }

    // Fill expr
    expr -> key = 0;
    expr -> txt = txt;

    // Return expr
    return expr;
}