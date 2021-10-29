#ifndef TRUTHTABLE_H
#define TRUTHTABLE_H

// -----------------> Types

typedef struct Truthtable {
    int var_count;
    int perm_count;
    char ** input;
    char * output;
    char * vars;
} truthtable_t;

// -----------------> Functions

truthtable_t * init_truthtable(int var_count);
void free_truthtable(truthtable_t * truthtable);

#endif