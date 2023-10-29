#ifndef STACK_H
#define STACK_H
#include "lib/poly.h"

typedef struct Stack *Stack_t;

// Create a new stack
Stack_t Stack_new();

// Push an element onto the stack
void Stack_push(Stack_t s, poly val);

// Pop an element off the stack. Assumes the stack is not empty.
int Stack_pop(Stack_t s);

// Check if the stack is empty
int Stack_isEmpty(Stack_t s);

// Destroy the stack and free all memory
void Stack_destroy(Stack_t s);

int Stack_size(Stack_t s);

char *Stack_toString (Stack_t stk);

Stack_t Stack_stack (poly x1, ...);


#endif
