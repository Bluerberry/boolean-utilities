// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>

#include "headers/expr.h"
#include "headers/globals.h"

// -----------------> Functions

// Creates a new globals list
globals_t * init_globals() {

    // Allocate globals
    globals_t * globals = malloc(sizeof(globals_t));
    if (globals == NULL) {
        printf("Error: Insufficient memory to allocate 'globals'\n");
        exit(-1);
    }

    // Fill globals
    for (int i = 0; i < 52; i++) {
        globals -> globals[i] = NULL;
    }

    // Return globals
    return globals;
}

// Hashes a key
size_t hash_key(char key) {
    if (key >= 'a' && key <= 'z') {
        return key - 'a';
    } else if (key >= 'A' && key <= 'Z') {
        return key - 'A' + 'z';
    } else {
        printf("Error: Could not find expression '%%%c'\n", key);
        exit(-1);
    }
}

// Finds an expression in globals
expr_t * find_expr(globals_t * globals, char key) {
    expr_t * expr = globals -> globals[hash_key(key)];
    
    // Check if expression exists
    if (expr == NULL) {
        printf("Error: Could not find expression '%%%c'\n", key);
        exit(-1);
    }

    // Return expression
    return expr;
}

// Assigns an expression to a key in globals
void set_expr(globals_t * globals, char key, expr_t * expr) {

    // Update new expression
    expr -> key = key;

    // Replace old expression
    size_t hash = hash_key(key);
    free(globals -> globals[hash]);
    globals -> globals[hash] = expr;
}