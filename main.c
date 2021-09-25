// -----------------> Dependencies

#include <stdio.h>

#include "headers/expr.h"
#include "headers/globals.h"
#include "headers/data.h"

// -----------------> Main 


int main(void) {
    stack_t * stack = init_stack();
    queue_t * queue = init_queue();

    push_stack(stack, 'a');
    push_stack(stack, 'b');
    push_stack(stack, 'c');

    printf("%c", pop_stack(stack));
    printf("%c", pop_stack(stack));
    printf("%c", pop_stack(stack));

    push_queue(queue, 'a');
    push_queue(queue, 'b');
    push_queue(queue, 'c');

    printf("\n%c", pop_queue(queue));
    printf("%c", pop_queue(queue));
    printf("%c", pop_queue(queue));

    free_stack(stack);
    free_queue(queue);

    return 0;
}