// -----------------> Dependencies

#include <stdio.h>

#include "headers/expr.h"
#include "headers/scope.h"
#include "headers/data.h"

// -----------------> Main 

int main(void) {
    scope_t global = init_scope();
    set_expr(global, 'a', init_expr("(a + b)!c"));
    printf("%s\n", find_expr(global, 'a'));
    free_scope(global);

    return 0;
}