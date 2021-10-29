
// -----------------> Dependencies

#include <stdio.h>

#include "headers/data.h"
#include "headers/expr.h"
#include "headers/scope.h"
#include "headers/solve.h"
#include "headers/truthtable.h"

// -----------------> Main 

int main(void) {
    scope_t global = init_scope();
    set_expr(global, 'f', init_expr("bca'"));

    truthtable_t * truthtable = solve_expr(global, find_expr(global, 'f'));

    printf("%s %c\n", truthtable -> vars, 'f');
    for (int i = 0; i < truthtable -> perm_count; i++)
        printf("%s %c\n", truthtable -> input[i], truthtable -> output[i]);
    
    free_scope(global);

    return 0;
}