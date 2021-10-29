#ifndef SCOPE_H
#define SCOPE_H

// -----------------> Types

typedef expr_t * scope_t;

// -----------------> Functions

scope_t init_scope();
expr_t find_expr(scope_t scope, char key);
void set_expr(scope_t scope, char key, char * expr);
void free_scope(scope_t scope);

#endif