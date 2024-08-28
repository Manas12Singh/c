#include <stdlib.h>
#include <string.h>

struct stack
{
    char *arr;
    int size, top;
};

void intialize(struct stack **s1, int cap)
{
    *s1 = (struct stack *)malloc(sizeof(struct stack));
    (*s1)->size = 0;
    (*s1)->top = -1;
    (*s1)->arr = (char *)malloc(cap);
}

void push(struct stack *s1, char val)
{
    s1->top++;
    s1->arr[s1->top] = val;
    s1->size++;
}

void pop(struct stack *s1)
{
    if (s1->size == 0)
        return;
    s1->top--;
    s1->size--;
}

void freeStack(struct stack **s1)
{
    free((*s1)->arr);
    free(*s1);
    *s1 = NULL;
}

int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '(':
        return 0;
    }
}

char *infixToPostfix(char *infix, int infixSize, int *r)
{
    char *s = (char *)malloc(infixSize + 1);
    int i = 0, j = 0;
    struct stack *s1;
    intialize(&s1, infixSize);
    while (infix[i] != '\0')
    {
        if (infix[i] >= 'a' && infix[i] <= 'z')
            s[j++] = infix[i++];
        else if (infix[i] == '(')
        {
            push(s1, infix[i++]);
        }
        else if (infix[i] == ')')
        {
            while (s1->arr[s1->top] != '(')
            {
                s[j++] = s1->arr[s1->top];
                pop(s1);
            }
            pop(s1);
            i++;
        }
        else
        {
            while (s1->size && (infix[i]) >= precedence(s1->arr[s1->top]))
            {
                s[j++] = s1->arr[s1->top];
                pop(s1);
            }
            push(s1, infix[i++]);
        }
    }
    while (s1->size)
    {
        s[j++] = s1->arr[s1->top];
        pop(s1);
    }
    s[j] = '\0';
    *r = j;
    return s;
}