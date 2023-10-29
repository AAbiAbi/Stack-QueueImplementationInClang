#ifndef QUEUE_H
#define QUEUE_H

#include "lib/poly.h"

typedef struct Queue *Queue_t;

Queue_t Queue_new();
void enqueue(Queue_t q, poly item);
poly dequeue(Queue_t q);
int isEmpty(Queue_t q);
poly peek(Queue_t q);
void Queue_destroy(Queue_t q);
int Queue_size(Queue_t q);

Queue_t Queue_queue(poly x1, ...);
char *Queue_toString(Queue_t q, char *(*tx)(poly));



#endif
