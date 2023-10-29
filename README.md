# Stack-QueueImplementationInClang
This lab is split into two parts. The first part concentrates on the implementation of stack. The second part deals with queue.

## Installation

Describe the installation process.

## Usage

### Stack
In this problem, you are required to implement the Stack_t ADT as we discussed in class. Download Project2-1.rar  Download Project2-1.rarto start with (the newly added files are stack.h, stack.c).

You may make use of any concrete representation for a linear list. 
And you may use either the method of boxing a linear list internally (as I did in the class) or write your own code from scratch (as this code does).

### Queue

Implement the Queue_t ADT as we talked about in class. Download Project2_2.rar Download Project2_2.rarto start with (the newly added files are queue.h and queue.c).

As in problem 1, you may use any concrete representation for a linear list. And you may use either the method of boxing a linear list internally (as I did in the class) or write your own code from scratch (as this code does).

Here, this problem makes use of a somewhat different data structure to represent a queue. You should read queue.c and we briefly explain the key idea here.

At any time, a queue is maintained internally as two separate lists: head and tail. The data structure for this reads:

typedef struct node{  poly data;  struct node *next;} *node; struct T{  node *tail;  node *head;  int size;};

where head points to head part of a queue, whereas tail points to tail part of queue in reverse order. For instance, for a queue

q = [2, 5, 7, 3, 4]

this data structure looks like:

tail = [4, 3, 7]head = [2, 5]

and it's easy to see that this equation (invariant)

q = head @ rev(tail)

holds, where @ stands for list concatenation and rev reverses a list.

Obviously, when enQueue a queue q, we should insert at the head of the list pointed by tail. And when deQueue, we should delete the head of the list pointed by head.

Question: What about we want to deQueue a queue, but head is empty?

## Contributing

Ningchen Liang nliang@scu.edu

Guide by Yancui 

## License

Include license information here, if applicable.
