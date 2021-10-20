// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>

#include "headers/expr.h"
#include "headers/scope.h"

// -----------------> Functions

// Hashes a key
static size_t hash_key(char key) {
    if (key >= 'a' && key <= 'z') {
        return key - 'a';
    } else if (key >= 'A' && key <= 'Z') {
        return key - 'A' + 'z';
    } else {
        printf("Error: Could not find expression '%%%c'\n", key);
        exit(-1);
    }
}

// Creates a new scope
scope_t * init_scope() {

    // Allocate scope
    scope_t * scope = malloc(sizeof(scope_t));
    if (scope == NULL) {
        printf("Error: Insufficient memory to allocate 'scope'\n");
        exit(-1);
    }

    // Fill scope
    for (int i = 0; i < 52; i++) {
        scope -> exprs[i] = NULL;
    }

    // Return scope
    return scope;
}

// Finds an expression in scope
expr_t * find_expr(scope_t * scope, char key) {
    expr_t * expr = scope -> exprs[hash_key(key)];
    
    // Check if expression exists
    if (expr == NULL) {
        printf("Error: Could not find expression '%%%c'\n", key);
        exit(-1);
    }

    // Return expression
    return expr;
}

// Assigns an expression to a key in scope
void set_expr(scope_t * scope, char key, expr_t * expr) {

    // Update new expression
    expr -> key = key;

    // Replace old expression
    size_t hash = hash_key(key);
    free(scope -> exprs[hash]);
    scope -> exprs[hash] = expr;
}