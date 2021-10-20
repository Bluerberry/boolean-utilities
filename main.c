// -----------------> Dependencies

#include <stdlib.h>

#include "headers/expr.h"
#include "headers/scope.h"
#include "headers/data.h"

// -----------------> Main 

int main(void) {
    scope_t * global = init_scope();
    set_expr(global, 'a', init_expr("(a + b)!c"));
    display_expr(find_expr(global, 'a'));

    return 0;
}