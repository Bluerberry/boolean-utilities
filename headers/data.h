#ifndef DATA_H
#define DATA_H

// -----------------> Structs

typedef struct Node {
    char content;
    struct Node * next;
} node_t;

typedef struct Stack {
    int length;
    node_t * head;
} stack_t;

typedef struct Queue {
    int length;
    node_t * head;
    node_t * tail;
} queue_t;

// -----------------> Functions

// Stack manipulation
stack_t * init_stack();
void free_stack(stack_t * stack);
void push_stack(stack_t * stack, char content);
char pop_stack(stack_t * stack);
int in_stack(stack_t * stack, char content);
char * concatenate_stack(stack_t * stack);

// Queue manipulation
queue_t * init_queue();
void free_queue(queue_t * queue);
void push_queue(queue_t * queue, char content);
char pop_queue(queue_t * queue);
int in_queue(queue_t * queue, char content);
char * concatenate_queue(queue_t * queue);

#endif