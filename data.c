
// -----------------> Dependencies

#include <stdlib.h>
#include <stdio.h>

#include "headers/data.h"

// -----------------> Functions

// Stack manipulation

// Creates a new stack instance
stack_t * init_stack() {
    stack_t * stack = malloc(sizeof(stack_t));
    if (stack == NULL) {
        printf("Error: Insufficient memory to allocate 'stack'\n");
        exit(-1);
    }
    
    stack -> length = 0;
    stack -> head = NULL;

    return stack;
}

// Copy stack onto new stack instance
stack_t * copy_stack(stack_t * stack) {
    stack_t * new_stack = init_stack();
    for (node_t * node = stack -> head; node; node = node -> next)
        push_stack(new_stack, node -> content);
    return new_stack;
}

// Empties the stack
void empty_stack(stack_t * stack) {
    while (stack -> length)
        pop_stack(stack);
}

// Frees stack and all its children
void free_stack(stack_t * stack) {
    empty_stack(stack);
    free(stack);
}

// Pushes a new node onto the stack
void push_stack(stack_t * stack, char content) {

    // Create new node
    node_t * node = malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Error: Insufficient memory to allocate 'node'\n");
        exit(-1);
    }

    node -> content = content;
    node -> next = stack -> head;

    // Push node
    stack -> head = node;
    stack -> length++;
}

// Pops a node from the stack
char pop_stack(stack_t * stack) {

    // Check for stacklength
    if (!stack -> length--) {
        printf("Error: Tried to pop from an empty stack\n");
        exit(-1);
    }

    // Gather content
    node_t * node = stack -> head;
    char content = node -> content;

    // Pop node
    stack -> head = node -> next;
    free(node);
    
    return content;
}

// Queue manipulation

// Creates a new queue instance
queue_t * init_queue() {
    queue_t * queue = malloc(sizeof(queue_t));
    if (queue == NULL) {
        printf("Error: Insufficient memory to allocate 'queue'\n");
        exit(-1);
    }

    queue -> length = 0;
    queue -> head = NULL;
    queue -> tail = NULL;

    return queue;
}

// Copy queue onto new queue instance
queue_t * copy_queue(queue_t * queue) {
    queue_t * new_queue = init_queue();
    for (node_t * node = queue -> head; node; node = node -> next)
        push_queue(new_queue, node -> content);
    return new_queue;
}

// Empties the queue
void empty_queue(queue_t * queue) {
    while (queue -> length)
        pop_queue(queue);
}

// Frees queue and all its children
void free_queue(queue_t * queue) {
    empty_queue(queue);
    free(queue);
}

// Pushes a new node onto the queue
void push_queue(queue_t * queue, char content) {

    // Create new node
    node_t * node = malloc(sizeof(node_t));
    if (node == NULL) {
        printf("Error: Insufficient memory to allocate 'node'\n");
        exit(-1);
    }

    node -> content = content;
    node -> next = NULL;

    // Push node
    if (queue -> length++)
        queue -> tail -> next = node;
    else
        queue -> head = node;
    queue -> tail = node;
}

// Pops a node from the queue
char pop_queue(queue_t * queue) {

    // Check for queuelength
    if (!queue -> length--) {
        printf("Error: Tried to pop from an empty queue\n");
        exit(-1);
    }

    // Gather content
    node_t * node = queue -> head;
    char content = node -> content;

    // Pop node
    queue -> head = node -> next;
    free(node);
    
    return content;
}

// Finds a node from in the queue
int in_queue(queue_t * queue, char content) {
    for (node_t * node = queue -> head; node; node = node -> next)
        if (node -> content == content)
            return 1;
    return 0;
}

// Concatenate queue into string
char * concatenate_queue(queue_t * queue) {
    int i = 0;

    // Create and copy string
    char * txt = malloc(queue -> length * sizeof(char));
    if (txt == NULL) {
        printf("Error: Insufficient memory to allocate 'txt'\n");
        exit(-1);
    }

    txt[queue -> length] = 0;

    for (node_t * node = queue -> head; node; node = node -> next)
        txt[i++] = node -> content; 

    return txt;
}
