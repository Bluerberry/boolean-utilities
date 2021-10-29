
// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

#include "headers/truthtable.h"

// -----------------> Functions

// Initializes an empty truthtable
truthtable_t * init_truthtable(int var_count) {
    truthtable_t * truthtable = malloc(sizeof(truthtable));
    truthtable -> perm_count  = pow(2, var_count);
    truthtable -> vars        = malloc(var_count * sizeof(char));
    truthtable -> output      = malloc(truthtable -> perm_count * sizeof(char));
    truthtable -> input       = malloc(truthtable -> perm_count * sizeof(char *));
    for (int i = 0; i < truthtable -> perm_count; i++)
        truthtable -> input[i] = malloc(var_count * sizeof(char));  

    return truthtable;   
}

// Free all aspects of a truthtable
void free_truthtable(truthtable_t * truthtable) {
    for (int i = 0; i < truthtable -> perm_count; i++)
        free(truthtable -> input[i]);
    free(truthtable -> output);
    free(truthtable -> vars);
    free(truthtable);
}