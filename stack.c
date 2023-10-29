#include <stdlib.h>
#include "stack.h"
#include <stdarg.h>
#include <stdio.h>
#include <string.h>


struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
    int size;   // <-- Add this to keep track of the number of elements
};

Stack_t Stack_new() {
    Stack_t s = malloc(sizeof(struct Stack));
    s->top = NULL;
    s->size = 0;  // Initialize size
    return s;
}

void Stack_push(Stack_t s, poly val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = s->top;
    s->top = newNode;
    s->size++;  // Increment the size after pushing
}

int Stack_pop(Stack_t s) {
    if (s->top == NULL) {
        // Error: stack is empty
        exit(1);
    }
    struct Node* temp = s->top;
    int poppedVal = temp->data;
    s->top = s->top->next;
    s->size--;  // Decrement the size after popping
    free(temp);
    return poppedVal;
}

int Stack_isEmpty(Stack_t s) {
    return s->top == NULL;
}

int Stack_size(Stack_t s) {
    return s->size;
}


void Stack_destroy(Stack_t s) {
    while (!Stack_isEmpty(s)) {
        Stack_pop(s);
    }
    free(s);
}


Stack_t Stack_stack(poly first, ...) {
    Stack_t s = Stack_new();
    va_list args;
    poly current = first;

    poly tempArr[100];  // Assuming a maximum of 100 arguments for simplicity
    int i = 0;

    va_start(args, first);
    while (current) {
        tempArr[i++] = current;
        current = va_arg(args, poly);
    }
    va_end(args);

    // Push onto the main stack in reverse order
    for (int j = i - 1; j >= 0; j--) {
        Stack_push(s, tempArr[j]);
    }

    return s;
}

char* Stack_toString(Stack_t stk) {
    // The size for the buffer can be calculated dynamically based on the
    // size of the stack and the expected size of each element's string representation.
    // For simplicity, we're using a fixed size here.
    char* buffer = (char*)malloc(1000); 
    if (!buffer) {
        return NULL; // Memory allocation failed
    }

    buffer[0] = '\0'; // Initialize to an empty string

    while (!Stack_isEmpty(stk)) {
        char temp[50];
        poly value = Stack_pop(stk);

        // Assuming poly is of integer type
        snprintf(temp, sizeof(temp), "%d ", value); 
        strcat(buffer, temp);
    }

    return buffer; 
}
