#ifndef SOLVE_H
#define SOLVE_H

#include "truthtable.h"

// -----------------> Functions

truthtable_t * solve_expr(scope_t scope, expr_t expr);

#endif