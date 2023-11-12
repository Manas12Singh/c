#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *top;
    int size;
} Stack;

Stack *initialise()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

Node *createNode(Node *next, int val)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    if (temp == NULL)
    {
        printf("Memory full.\n");
        return NULL;
    }
    temp->data = val;
    temp->next = next;
    return temp;
}

void push(Stack *s, int val)
{
    Node *temp = createNode(s->top, val);
    if (temp == NULL)
        return;
    s->top = temp;
    s->size++;
}

void pop(Stack *s)
{
    if (s->size == 0)
    {
        printf("Stack already empty.\n");
        return;
    }
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    s->size--;
}

void peek(Stack *s)
{
    if (s->size == 0)
        printf("Stack is empty.\n");
    else
        printf("%d\n", s->top->data);
}

void freeNode(Node **n)
{
    while (*n != NULL)
    {
        Node *temp = *n;
        *n = (*n)->next;
        free(temp);
    }
}

void freeStack(Stack **s)
{
    if (*s == NULL)
        return;
    freeNode(&((*s)->top));
    free(*s);
    *s = NULL;
}

int main()
{
    Stack *s = initialise();
    while (1)
    {
        int opt, n;
        printf("Options: \n1. Push. \n2. Pop. \n3. Peek. \n4. Exit.\n");
        printf("Enter your choice (1 to 4): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("Enter the value: ");
            scanf("%d", &n);
            push(s, n);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            peek(s);
            break;
        case 4:
            freeStack(&s);
            return 0;
        default:
            printf("Wrong Choice!\n");
        }
    }
}