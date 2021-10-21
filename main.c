// -----------------> Dependencies

#include <stdio.h>

#include "headers/data.h"
#include "headers/expr.h"
#include "headers/scope.h"
#include "headers/solve.h"

// -----------------> Main 

int main(void) {
    scope_t global = init_scope();
    set_expr(global, 'f', init_expr("a(b ! c)"));
    set_expr(global, 'b', init_expr("ac"));
    set_expr(global, 'c', init_expr("0"));
    
    queue_t * trace = init_queue();
    printf("%s", expand_expr(global, find_expr(global, 'f'), trace));

    free_scope(global);

    return 0;
}