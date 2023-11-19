#ifndef STDIO_H
#include <stdio.h>
#endif

#ifndef STDLIB_H
#include <stdlib.h>
#endif

#ifndef STACK_H
#define STACK_H

struct Node
{
	void *data;
	struct Node *next;
};

typedef struct
{
	struct Node *top;
	int dataSize;
} Stack;

Stack *createStack(int);
void push(Stack *, void *);
void *top(Stack *);
void pop(Stack *);
void destroyStack(Stack **);
short isEmpty(Stack *);

#endif // STACK_H
