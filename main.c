// -----------------> Dependencies

#include <stdio.h>

#include "headers/expr.h"
#include "headers/globals.h"

// -----------------> Main 


int main(void) {
    globals_t * globals = init_globals();
    expr_t * expr1 = init_expr("test");
    expr_t * expr2 = init_expr("succes");

    set_expr(globals, 'a', expr1);
    set_expr(globals, 'a', expr2);

    printf("%s\n", find_expr(globals, 'a') -> txt);

    return 0;
}