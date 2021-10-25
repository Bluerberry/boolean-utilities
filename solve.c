// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "headers/data.h"
#include "headers/expr.h"
#include "headers/scope.h"
#include "headers/solve.h"

// -----------------> Functions

// Recursively fills an expression
static expr_t expand_expr(scope_t scope, expr_t expr, queue_t * trace) {

    // Fill nested expressions
    queue_t * expanding_expr = init_queue();
    for (int i = 0; i < strlen(expr); i++) {
        char c = expr[i];

        // Parse char
        if (((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) && find_expr(scope, c) != NULL) {

            // Check trace
            if (in_queue(trace, c)) {
                printf("Error: Expression '%c' infinitely recurs, ", trace -> head -> content);
                for (node_t * node = trace -> head; node; node = node -> next)
                    printf("%c > ", node -> content);
                printf("%c.\n", c);
                exit(-1);
            }

            // Expand trace
            queue_t * new_trace = copy_queue(trace);
            push_queue(new_trace, c);

            // Expand nested expression
            expr_t nested_expr = expand_expr(scope, find_expr(scope, c), new_trace);

            // Push expression
            push_queue(expanding_expr, '(');
            for (int i = 0; i < strlen(nested_expr); i++)
                push_queue(expanding_expr, nested_expr[i]);
            push_queue(expanding_expr, ')');

            // Free nested expression
            free(nested_expr);
        } else {
            push_queue(expanding_expr, c);
        }
    }

    // Create expanded expression
    expr_t expanded_expr = concatenate_queue(expanding_expr);

    // Free variables
    free_queue(expanding_expr);
    free_queue(trace);

    // Return expanded expression
    return expanded_expr;
}

// Solve an expression
void solve_expr(scope_t scope, expr_t expr) {
    
    // Expand expression
    queue_t * trace = init_queue();
    expr_t expanded_expr = expand_expr(scope, expr, trace);

    // Convert to postfix
    queue_t * queue = init_queue();
    stack_t * stack = init_stack();

    // Shunting-Yard algorithm
    for (int i = 0; i < strlen(expanded_expr); i++) {
        char c = expanded_expr[i];

        if (c == '0' || c == '1' || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
            push_queue(queue, c);
        } else if (c == '\'') {
            push_queue(queue, '!');
        } else if (c == '(' || c == '!') {
            push_stack(stack, c);
        } else if (c == ')') {
            while (stack -> head -> content != '(')
                push_queue(queue, pop_stack(stack));
            pop_stack(stack);
            if (stack -> head && stack -> head -> content == '!')
                push_queue(queue, pop_stack(stack));            
        } else {
            while (
                stack -> length > 0 &&
                stack -> head -> content != '(' &&
                (stack -> head -> content != '+' || c == '+')
            ) {
                push_queue(queue, pop_stack(stack));
            }

            push_stack(stack, c);
        }
    }

    // Create postfix expression
    while (stack -> length > 0)
        push_queue(queue, pop_stack(stack));
    expr_t postfix_expr = concatenate_queue(queue);

    printf("%s\n", postfix_expr);

    // Free variables
    free(expanded_expr);
    free(postfix_expr);
    free_queue(queue);
    free_stack(stack);
}