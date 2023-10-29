#include <stdio.h>
#include "stack.h"
#include <stdlib.h>


int main() {
    Stack_t stack = Stack_new();

    // We're casting integers to void* for pushing onto the stack.
    Stack_push(stack, (poly)(intptr_t)10);
    Stack_push(stack, (poly)(intptr_t)20);
    Stack_push(stack, (poly)(intptr_t)30);
    double myDouble = 5.6;
    double* ptr = malloc(sizeof(double));
    *ptr = myDouble;
    Stack_push(stack, (poly)ptr);

    printf("Popped %d from the stack.\n", Stack_pop(stack)); // Should print 30
    printf("Popped %d from the stack.\n", Stack_pop(stack)); // Should print 20
    printf("Stack size after popping: %d\n", Stack_size(stack));

    Stack_push(stack, (poly)(intptr_t)40);
    printf("Popped %d from the stack.\n", Stack_pop(stack)); // Should print 40
    printf("Stack size after pushing 40: %d\n", Stack_size(stack));

    Stack_destroy(stack);

    Stack_t s = Stack_stack(3, 4, 5, 0);
    printf("it is  %s that stack is empty\n", Stack_isEmpty(stack)? "true" : "false");
    printf("Popped %d from the stack.\n", Stack_pop(stack)); // Should print 3
    
    char* stackStr = Stack_toString(s);
    printf("Stack contents: %s\n", stackStr); 
    Stack_destroy(s);

    return 0;
}
