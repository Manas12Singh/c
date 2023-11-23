#ifndef STACK_H
#define STACK_H
#include <stdio.h>
#include <stdlib.h>

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

#endif
