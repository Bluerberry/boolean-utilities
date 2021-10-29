
// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "headers/expr.h"
#include "headers/scope.h"
#include "headers/solve.h"

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

        // Handle set command
        if (!strcmp(cmd, "set")) {
            // Get key
            char * key = strtok(NULL, "=");
            if (key == NULL) {
                printf("Error: Expected key\n");
                exit(-1);
            }

            // Get expression
            char * expr = strtok(NULL, "\n");
            if (expr == NULL) {
                printf("Error: Expected expression\n");
                exit(-1);
            }

            // Set expression
            set_expr(global, *key, expr);
        
        // Handle solve command
        } else if (!strcmp(cmd, "solve")) {
            // Get expression
            char * expr = strtok(NULL, "\n");
            if (expr == NULL) {
                printf("Error: Expected expression\n");
                exit(-1);
            }

            // Solve expression
            truthtable_t * truth = solve_expr(global, init_expr(expr));

            // Display truthtable
            printf("%s\n", truth -> vars);
            for (int i = 0; i <= truth -> var_count; i++)
                printf("─");
            printf("┐\n");
            for (int i = 0; i < truth -> perm_count; i++)
                printf("%s │ %c\n", truth -> input[i], truth -> output[i]);

        // Handle unknown commands
        } else {
            printf("Error: Unknown command '%s'\n", cmd);
            exit(-1);
        }
    }

    return 0;
}