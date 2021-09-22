#ifndef GLOBALS_H
#define GLOBALS_H

// -----------------> Structs

typedef struct Globals {
    expr_t * globals[52];
} globals_t;

// -----------------> Functions

globals_t * init_globals();
size_t hash_key(char key);
expr_t * find_expr(globals_t * globals, char key);
void set_expr(globals_t * globals, char key, expr_t * expression);

#endif