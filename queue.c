#include <stdlib.h>
#include "queue.h"
#include "assert.h"
#include <stdarg.h>
#include <string.h>

typedef struct Node {
    poly item;
    struct Node *next;
} Node;

struct Queue {
    Node *front;
    Node *rear;
    int size;
    
};

Queue_t Queue_new() {
    Queue_t q = malloc(sizeof(struct Queue));
    assert(q != NULL);

    q->front = NULL;
    q->rear = NULL;
    q->size = 0;

    return q;
}

void enqueue(Queue_t q, poly item) {
    Node *newNode = malloc(sizeof(Node));
    assert(newNode != NULL);

    newNode->item = item;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
    q->size++;
}

poly dequeue(Queue_t q) {
    if (isEmpty(q)) {
        return NULL;
        // Sentinel value indicating queue is empty
    }

    Node *temp = q->front;
    poly item = temp->item;

    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    q->size--;

    return item;
}

int isEmpty(Queue_t q) {
    return q->size == 0;
}

int Queue_size(Queue_t q) {
    return q->size;
}


Queue_t Queue_queue(poly x1, ...) {
    Queue_t q = Queue_new();
    va_list args;
    poly current = x1;

    va_start(args, x1);
    while (current) {
        enqueue(q, current);
        current = va_arg(args, poly);
    }
    va_end(args);

    return q;
}

char *Queue_toString(Queue_t q, char *(*tx)(poly)) {
    Node *current = q->front;
    char *result = malloc(1);
    result[0] = '\0';

    while (current) {
        char *itemStr = tx(current->item);
        char *newResult = malloc(strlen(result) + strlen(itemStr) + 3); // for space, comma, and null terminator
        strcpy(newResult, result);
        strcat(newResult, itemStr);
        strcat(newResult, ", ");
        free(result);
        free(itemStr);
        result = newResult;
        current = current->next;
    }

    return result;
}

poly peek(Queue_t q) {
    if (isEmpty(q)) {
        return NULL;
    }

    return q->front->item;
}

void Queue_destroy(Queue_t q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }

    free(q);
}
