#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} Node;

typedef struct
{
    Node *front, *back;
    int size;
} Queue;

Queue *initialise()
{
    Queue *s = (Queue *)malloc(sizeof(Queue));
    s->size = 0;
    s->front = s->back = NULL;
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

void push(Queue *s, int val)
{
    Node *temp = createNode(NULL, val);
    if (temp == NULL)
        return;
    if (s->front == NULL)
        s->front = s->back = temp;
    else
        s->back->next = temp, s->back = temp;
    s->size++;
}

void pop(Queue *s)
{
    if (s->size == 0)
    {
        printf("Queue already empty.\n");
        return;
    }
    if (s->size == 1)
        s->back = NULL;
    Node *temp = s->front;
    s->front = s->front->next;
    free(temp);
    s->size--;
}

void peek(Queue *s)
{
    if (s->size == 0)
        printf("Queue is empty.\n");
    else
        printf("%d\n", s->front->data);
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

void freeStack(Queue **s)
{
    if (*s == NULL)
        return;
    freeNode(&((*s)->front));
    free(*s);
    *s = NULL;
}

int main()
{
    Queue *s = initialise();
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