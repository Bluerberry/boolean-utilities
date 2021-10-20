// -----------------> Dependencies

#include <stdlib.h>

#include "headers/expr.h"
#include "headers/globals.h"
#include "headers/data.h"

// -----------------> Main 


int main(void) {
    expr_t * expr = init_expr("(a + b)!c");
    display_expr(expr);
    free_expr(expr);

    return 0;
}