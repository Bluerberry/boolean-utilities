// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "headers/data.h"
#include "headers/expr.h"
#include "headers/scope.h"

// -----------------> Functions

// Creates a new expression
expr_t init_expr(char * txt) {

    // Variables
    queue_t * parsed_expr = init_queue();
    int bracket = 0;         // Keeps track if all brackets have been closed
    int accept_operator = 0; // True if previous char can accept an operator

    // Parse expression
    for (int i = 0; i < strlen(txt); i++) {
        char c = txt[i];

        // Skip spaces
        if (c == ' ')
            continue;

        // Parse character
        if (c == '0' || c == '1' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (accept_operator) push_queue(parsed_expr, '*');
            accept_operator = 1;
        } else if (c == '(') {
                if (accept_operator) push_queue(parsed_expr, '*');
                accept_operator = 0;
                bracket++;
        } else if (c == '!') {
                if (accept_operator) push_queue(parsed_expr, '*');
                accept_operator = 0;
        } else if (accept_operator) {
            if (c == '\'') {
                accept_operator = 1;
            } else if (c == ')') {
                accept_operator = 1;
                bracket--;
            } else if (c == '*' || c == '+' || c == '^') {
                accept_operator = 0;
            } else {
                printf("Error: Unkown character found '%c'\n", c);
                exit(-1);
            }
        } else {
            printf("Error: Unxpected operator '%c'\n", c);
            exit(-1);
        }      

        // Check for mismatched brackets
        if (bracket < 0) {
            printf("Error: Mismatched brackets found\n");
            exit(-1);
        }

        // Update expression
        push_queue(parsed_expr, c);
    }

    // Check for floating operators
    if (!accept_operator) {
        printf("Error: Floating operand found\n");
        exit(-1);
    }  

    // Check for mismatched brackets
    if (bracket != 0) {
        printf("Error: Mismatched brackets found\n");
        exit(-1);
    }

    // Create expr
    expr_t expr = concatenate_queue(parsed_expr);

    // Free queue
    free_queue(parsed_expr);

    // Return expr
    return expr;
}