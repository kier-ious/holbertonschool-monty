# Stack and Queues, LIFO, FIFO
 
In computer science, stacks and queues are fundamental data structures used to store and manage collections of elements. They have specific rules for adding and removing elements, which are characterized by the principles of Last-In-First-Out (LIFO) and First-In-First-Out (FIFO), respectively. Let's explore these concepts:
## Stack:
A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. Imagine it like a stack of plates where you can only add or remove plates from the top. The last plate added is the first one to be removed.
    * Operations:
    * Push: Adding an element to the top of the stack.
    * Pop: Removing the element from the top of the stack.
    * Peek (or Top): Viewing the top element without removing it.
    * IsEmpty: Checking if the stack is empty.
## Queue:
A queue is also a linear data structure, but it follows the First-In-First-Out (FIFO) principle. Imagine it like a line of people waiting in a queue. The person who enters the queue first is the first one to leave.
    * Operations:
    * Enqueue: Adding an element to the back of the queue.
    * Dequeue: Removing the element from the front of the queue.
    * Front: Viewing the front element without removing it.
    * Rear (or Back): Viewing the back element without removing it.
    * IsEmpty: Checking if the queue is empty.

## LIFO (Last-In-First-Out):
LIFO is a principle where the most recently added item is the first one to be removed. This is the behavior of a stack. Think of it as a stack of books. You can only add or remove books from the top of the stack. The book you put on last will be the first one you take off.
## FIFO (First-In-First-Out):
FIFO is a principle where the first item added is the first one to be removed. This is the behavior of a queue. Think of it as people waiting in line. The person who joined the line first will be the first one to exit.

## To summarize:
* Stacks are used for managing data in a way that the last item added is the first one to be processed or removed.
* Queues are used for managing data in a way that the first item added is the first one to be processed or removed.
Both stacks and queues have various applications in computer science and software development. Stacks are often used for managing function calls, undo operations, and expressions evaluation, while queues are used in scenarios like task scheduling, breadth-first search algorithms, and managing requests in networking.

## Extern:  What it is and how to use it

Using extern is only of relevance when the program you're building consists of multiple source files linked together, where some of the variables defined, for example, in source file file1.c need to be referenced in other source files, such as file2.c.

## It is important to understand the difference between defining a variable and declaring a variable:
* A variable is declared when the compiler is informed that a variable exists (and this is its type); it does not allocate the storage for the variable at that point.
* A variable is defined when the compiler allocates the storage for the variable.
You may declare a variable multiple times (though once is sufficient); you may only define it once within a given scope. A variable definition is also a declaration, but not all variable declarations are definitions.

## Best way to declare and define global variables
The clean, reliable way to declare and define global variables is to use a header file to contain an extern declaration of the variable.
The header is included by the one source file that defines the variable and by all the source files that reference the variable. For each program, one source file (and only one source file) defines the variable. Similarly, one header file (and only one header file) should declare the variable. The header file is crucial; it enables cross-checking between independent TUs (translation units — think source files) and ensures consistency.
Although there are other ways of doing it, this method is simple and reliable. It is demonstrated by file3.h, file1.c and file2.c:

### file3.h
extern int global_variable;  /* Declaration of the variable */

### file1.c
#include "file3.h"  /* Declaration made available here */
#include "prog1.h"  /* Function declarations */

/* Variable defined here */
int global_variable = 37;    /* Definition checked against declaration */

int increment(void) { return global_variable++; }

file2.c
#include "file3.h"
#include "prog1.h"
#include <stdio.h>

void use_it(void)
{
    printf("Global variable: %d\n", global_variable++);
}


### What is a stack and when should you use it?

- A stack is a logical concept that consists of a set of similar elements. The term is often used in programming and memory organization in computers. Programming stacks are based on the principle of last in first out (LIFO), a commonly used type of data abstract that consists of two major operations, push and pop.

- A Stack can be used for evaluating expressions consisting of operands and operators. Stacks can be used for Backtracking, i.e., to check parenthesis matching in an expression. It can also be used to convert one form of expression to another form. It can be used for systematic Memory Management.



## What is a queue and when should you use it?

- A queue is a linear data structure that stores the elements sequentially. It uses the FIFO approach (First In First Out) for accessing elements. Queues are typically used to manage threads in multithreading and implementing priority queuing systems.

- Queue is used when things don't have to be processed immediately, but have to be processed in First In First Out order.



## What are the common implementations of stacks and queues

- Stacks are implemented using an array or linked list data structure. Queues are implemented using an array or linked list data structure. Delete operation is called pop operation. Delete operation is called dequeue operation.


## What are the common use cases of stacks and queues?

- Stacks are used in cache based applications, like recently opened/used application will comes up. Queues are used in deleting/remove the data, like first inserted data needs to be deleted at first.


## Which of the following are common uses of a stack?

Following is the various Applications of Stack in Data Structure:
* Evaluation of Arithmetic Expressions.
* Backtracking.
* Delimiter Checking.
* Reverse a Data.
* Processing Function Calls.


## What are the use cases of queue?

The following are some of the most common queue applications in data structure:
* Managing requests on a single shared resource such as CPU scheduling and disk scheduling.
* Handling hardware or real-time systems interrupts.
* Handling website traffic.
* Routers and switches in networking.
* Maintaining the playlist in media players.

## What is the proper way to use global variables

- The global variables get defined outside any function- usually at the very beginning/top of a program. After this, the variables hold their actual values throughout the lifetime of that program, and one can access them inside any function that gets defined for that program.
