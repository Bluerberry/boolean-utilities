
// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "headers/expr.h"
#include "headers/scope.h"

#define MAX_LINE_SIZE 255

// -----------------> Main 

int main(int argc, char * argv[]) {
    
    // Gather filename
    if (argc != 2) {
        printf("Error: Expected command line argument\n");
        exit(-1);
    }

    // Create global scope
    scope_t global = init_scope();

    // Gather file
    FILE * file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: File '%s' could not be opened\n", argv[1]);
        exit(-1);
    }

    // Read file
    char cmd[MAX_LINE_SIZE], line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, file)) {

        // Gather command
        strcpy(cmd, line);
        strtok(cmd, " \n");

        // Handle set expression command
        if (!strcmp(cmd, "expr")) {
            char * key = strtok(NULL, "=");
            if (key == NULL) {
                printf("Error: Expected key\n");
                exit(-1);
            }

            char * expr = strtok(NULL, "\n");
            if (expr == NULL) {
                printf("Error: Expeted expression\n");
                exit(-1);
            }

            set_expr(global, *key, init_expr(expr));

        // Handle unknown commands
        } else {
            printf("Error: Unknown command '%s'\n", cmd);
            exit(-1);
        }
    }

    return 0;
}