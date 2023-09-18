#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int *arr;
    int capacity, size, top;
};

void intialize(struct stack **s1)
{
    *s1 = (struct stack *)malloc(sizeof(struct stack));
    (*s1)->capacity = 2;
    (*s1)->size = 0;
    (*s1)->top = -1;
    (*s1)->arr = (int *)malloc(sizeof(int) * 2);
}

void push(struct stack *s1, int val)
{
    if (s1->size == s1->capacity)
    {
        s1->arr = (int *)realloc(s1->arr, sizeof(int) * (2 * s1->capacity));
        s1->capacity *= 2;
    }
    s1->top++;
    s1->arr[s1->top] = val;
    s1->size++;
}

void pop(struct stack *s1)
{
    if (s1->size == 0)
    {
        printf("Stack already empty!\n");
        return;
    }
    printf("%d\n", s1->arr[s1->top]);
    s1->top--;
    s1->size--;
    if (s1->size = s1->capacity / 2)
    {
        s1->capacity /= 2;
        s1->arr = (int *)realloc(s1->arr, sizeof(int) * s1->capacity);
    }
}

void top(struct stack *s1)
{
    if (s1->size == 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("%d\n", s1->arr[s1->top]);
}

void print(struct stack *s1)
{
    if (s1->size == 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    int n = s1->top;
    while (n >= 0)
        printf("%d ", s1->arr[n--]);
    printf("\n");
}

void freeStack(struct stack **s1)
{
    free((*s1)->arr);
    free(*s1);
    *s1 = NULL;
}