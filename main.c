// -----------------> Dependencies

#include <stdio.h>

#include "headers/data.h"
#include "headers/expr.h"
#include "headers/scope.h"
#include "headers/solve.h"

// -----------------> Main 

int main(void) {
    scope_t global = init_scope();
    set_expr(global, 'f', init_expr("(b ! c)a"));

    solve_expr(global, find_expr(global, 'f'));
    
    free_scope(global);

    return 0;
}