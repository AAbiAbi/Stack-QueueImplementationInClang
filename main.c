#include <stdio.h>
#include "queue.h"
#include <stdlib.h>

char *intToString(poly p) {
    int val = (int)(intptr_t)p;
    char *buffer = malloc(15 * sizeof(char));  // Assuming an integer won't be more than 15 characters
    sprintf(buffer, "%d", val);
    return buffer;
}

int main() {
    Queue_t q = Queue_new();

    enqueue(q, (poly)(intptr_t)1);
    enqueue(q, (poly)(intptr_t)2);
    enqueue(q, (poly)(intptr_t)3);

    printf("Front of queue: %d\n", (int)(intptr_t)peek(q));  // should print 1
    printf("Size: %d\n", Queue_size(q));                      // should print 3
    printf("Is queue empty? %d\n", isEmpty(q));               // should print 0

    char *str = Queue_toString(q, intToString);
    printf("Queue as string: %s\n", str);
    free(str);

    printf("Dequeued: %d\n", (int)(intptr_t)dequeue(q));      // should print 1
    printf("Size after dequeue: %d\n", Queue_size(q));        // should print 2

    Queue_destroy(q);
    return 0;
}
