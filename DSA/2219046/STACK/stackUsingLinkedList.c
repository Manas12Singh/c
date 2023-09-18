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

void freeStack(struct stack **s1)
{
    freeList(&((*s1)->head));
    free(*s1);
    *s1 = NULL;
}

int main()
{
    struct stack *s1 = NULL;
    while (1)
    {
        int opt, k;
        printf("Options: \n1. Create a new stack. \n2. Push. \n3. Pop. \n4. Top. \n5. Print. \n6. Exit.\n");
        printf("Enter your choice (1 to 6): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            intialize(&s1);
            break;
        case 2:
            printf("Enter the value: ");
            scanf("%d", &k);
            push(s1, k);
            break;
        case 3:
            pop(s1);
            break;
        case 4:
            top(s1);
            break;
        case 5:
            print(s1);
            break;
        case 6:
            freeStack(&s1);
            return 0;
        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}
