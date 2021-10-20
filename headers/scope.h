#ifndef SCOPE_H
#define SCOPE_H

// -----------------> Structs

typedef struct Scope {
    expr_t * exprs[52];
} scope_t;

// -----------------> Functions

scope_t * init_scope();
expr_t * find_expr(scope_t * scope, char key);
void set_expr(scope_t * scope, char key, expr_t * expression);

#endif