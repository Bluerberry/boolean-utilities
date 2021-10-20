// -----------------> Dependencies

#include <stdio.h>

#include "headers/expr.h"
#include "headers/globals.h"
#include "headers/data.h"

// -----------------> Main 


int main(void) {
    expr_t * expr = init_expr("(a + b)!c");
    printf("%s\n", expr -> txt);
    printf("%s\n", expr -> vars);

    return 0;
}