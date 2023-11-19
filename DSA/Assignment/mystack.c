#include "mystack.h"

Stack *createStack(int dataSize)
{
	Stack *temp = (Stack *)malloc(sizeof(Stack));
	temp->top = NULL;
	temp->dataSize = dataSize;
	return temp;
}

void push(Stack *s1, void *data)
{
	struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
	if (!temp)
	{
		printf("Memory full!\n");
		return;
	}
	temp->data = data;
	temp->next = s1->top;
	s1->top = temp;
}

void *top(Stack *s1)
{
	if (s1->top == NULL)
		return NULL;
	return s1->top->data;
}

void pop(Stack *s1)
{
	if (s1->top == NULL)
	{
		printf("Stack already empty!\n");
		return;
	}
	struct Node *temp = s1->top;
	s1->top = temp->next;
	free(temp->data);
	free(temp);
}

short isEmpty(Stack *s)
{
	return s == NULL || s->top == NULL;
}

void freeList(struct Node **head)
{
	if ((*head)->next != NULL)
		freeList(&((*head)->next));
	free((*head)->data);
	free(*head);
	*head = NULL;
}

void destroyStack(Stack **s1)
{
	freeList(&((*s1)->top));
	free(*s1);
	*s1 = NULL;
}