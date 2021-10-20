// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "headers/data.h"
#include "headers/expr.h"

// -----------------> Functions

// Creates a new globals list
expr_t * init_expr(char * txt) {

    // Allocate globals
    expr_t * expr = malloc(sizeof(expr_t));
    if (expr == NULL) {
        printf("Error: Insufficient memory to allocate 'expr'\n");
        exit(-1);
    }

    // Variables
    queue_t * parsed_expr = init_queue();
    queue_t * variables = init_queue();
    int bracket = 0; // Keeps track if all brackets have been closed
    int operand = 0; // True if previous char can accept an operand
    int nested = 0;  // True if expecting a nested expression

    // Parse expression
    for (int i = 0; i < strlen(txt); i++) {
        char c = txt[i];

        // Skip spaces
        if (c == ' ')
            continue;

        // Insert missing operands
        if (operand && (c == '(' || c == '!' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')))
            push_queue(parsed_expr, '*');

        // Parse character
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            if (!nested && !in_queue(variables, c))
                push_queue(variables, c);
            operand = 1;
            nested = 0;
        } else if (!nested) {
            if (c == '(') {
                operand = 0;
                bracket++;
            } else if (c == ')') {
                operand = 1;
                bracket--;
            } else if (c == '%') {
                operand = 0;
                nested = 1;
            } else if (c == '!' || c == '*' || c == '+' || c == '^') {
                operand = 0;
            } else {
                printf("Error: Unkown character found '%c'\n", c);
                exit(-1);
            }
        } else {
            printf("Error: Expected a nested expression\n");
            exit(-1);
        }

        // Update expression
        push_queue(parsed_expr, c);
    }

    // Check for mismatched brackets
    if (bracket) {
        printf("Error: Mismatched brackets found\n");
        exit(-1);
    }

    // Fill expr
    expr -> key = '?';
    expr -> txt = concatenate_queue(parsed_expr);
    expr -> vars = concatenate_queue(variables);

    // Free variables
    free_queue(parsed_expr);
    free_queue(variables);

    // Return expr
    return expr;
}

// Displays an expression
void display_expr(expr_t * expr) {
    printf("Displaying expression '%c':\n\tText: %s\n\tVars: %s\n", expr -> key, expr -> txt, expr -> vars);
}

// Frees an expression
void free_expr(expr_t * expr) {
    free(expr -> txt);
    free(expr -> vars);
    free(expr);
}