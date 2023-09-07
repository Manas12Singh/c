#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct stack
{
    struct Node *head;
    int size;
};

void intialize(struct stack **s1)
{
    *s1 = (struct stack *)malloc(sizeof(struct stack));
    (*s1)->head = NULL;
    (*s1)->size = 0;
}

void push(struct stack *s1, int val)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }
    temp->data = val;
    temp->next = s1->head;
    s1->head = temp;
    s1->size++;
}

void print(struct stack *s1)
{
    struct Node *trav = s1->head;
    if (!trav)
    {
        printf("Empty List!");
    }
    while (trav)
    {
        printf("%d ", trav->data);
        trav = trav->next;
    }
    printf("\n");
}

void top(struct stack *s1)
{
    if (s1->size == 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("%d\n", s1->head->data);
}

void pop(struct stack *s1)
{
    if (s1->size == 0)
    {
        printf("Stack already empty!\n");
        return;
    }
    printf("%d\n", s1->head->data);
    struct Node *temp = s1->head;
    s1->head = temp->next;
    free(temp);
    s1->size--;
}

void freeList(struct Node **head)
{
    if ((*head)->next != NULL)
        freeList(&((*head)->next));
    free(*head);
    *head = NULL;
}

void empty(struct stack *s1)
{
    freeList(&(s1->head));
}