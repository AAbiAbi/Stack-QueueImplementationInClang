# Stack-QueueImplementationInClang
This lab is split into two parts. The first part concentrates on the implementation of stack. The second part deals with queue.
This repository contains an implementation of a generic Queue ADT (Abstract Data Type) in C

##Queue Implementation
Our queue implementation follows the First-In-First-Out (FIFO) principle. The primary operations supported are:

Enqueue: Add an item to the end of the queue.
Dequeue: Remove and return the item from the front of the queue.
Peek: View the item at the front without removing it.
isEmpty: Check if the queue is empty.
Queue Size: Return the number of elements in the queue.

Usage:
```c
#include "queue.h"

int main() {
    Queue_t myQueue = Queue_new();     // Create a new queue
    enqueue(myQueue, (poly)item);      // Add items to the queue
    poly frontItem = dequeue(myQueue); // Retrieve and remove the front item
    poly topItem = peek(myQueue);      // View the front item without removing
    int size = Queue_size(myQueue);    // Get the number of items in the queue
    bool empty = isEmpty(myQueue);     // Check if the queue is empty
    
    // Clean up
    Queue_destroy(myQueue);
    return 0;
}
```
Note: poly is a placeholder for a generic type. Replace it with your actual datatype.

###Additional Features:
Queue to String: This feature lets you convert the queue's contents to a string representation. Useful for debugging and visualization.
```c
char *queueStr = Queue_toString(myQueue, someFunctionToConvertPolyToString);
printf("Queue: %s\n", queueStr);
free(queueStr);
```
###Contribution:
Ningchen Liang nliang@scu.edu

