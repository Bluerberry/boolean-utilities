// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "headers/data.h"
#include "headers/expr.h"

// -----------------> Functions

// Creates a new expression
expr_t init_expr(char * txt) {

    // Variables
    queue_t * parsed_expr = init_queue();
    int bracket = 0; // Keeps track if all brackets have been closed
    int operand = 0; // True if previous char can accept an operand

    // Parse expression
    for (int i = 0; i < strlen(txt); i++) {
        char c = txt[i];

        // Skip spaces
        if (c == ' ')
            continue;

        // Parse character
        if (c == '0' || c == '1' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (operand) push_queue(parsed_expr, '*');
            operand = 1;
        } else if (c == '(') {
            if (operand) push_queue(parsed_expr, '*');
            operand = 0;
            bracket++;
        } else if (c == ')') {
            operand = 1;
            bracket--;
        } else if (c == '!') {
            if (operand) push_queue(parsed_expr, '*');
            operand = 0;
        } else if (c == '*' || c == '+' || c == '^') {
            if (!operand) {
                printf("Error: Unexpected operand found '%c'\n", c);
                exit(-1);
            } operand = 0;
        } else {
            printf("Error: Unkown character found '%c'\n", c);
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