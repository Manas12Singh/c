#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head;

void create(int n)
{
    struct node *temp;
    int data;
    printf("enter data 1\n");
    scanf("%d", &data);
    head = (struct node *)malloc(sizeof(struct node));
    head->data = data;
    head->next = NULL;
    temp = head;
    for (int i = 2; i <= n; i++)
    {
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("enter data %d\n", i);
        scanf("%d", &data);
        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

struct node *reverse(int k)
{
    struct node *sp = (struct node *)malloc(sizeof(struct node));
    sp->next = head;
    struct node *temp1 = head;
    struct node *temp2 = head;
    while (temp2 != NULL)
    {
        if (temp2->data == k)
        {
            break;
        }   
        temp2 = temp2->next;
    }

    struct node *prev = NULL;
    struct node *next;
    while (temp1 != temp2)
    {
        next = temp1->next;
        temp1->next = prev;
        prev = temp1;
        temp1 = next;
    }
    temp2 = temp2->next;
    struct node *prev1 = NULL;
    struct node *next1;
    while (temp2 != NULL)
    {
        next1 = temp2->next;
        temp2->next = prev1;
        prev1 = temp2;
        temp2 = next1;
    }
    temp1->next = prev1;
    return sp->next;
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data); // Add a space here
        temp = temp->next;
    }
    printf("\n"); // Add a new line here
}

int main()
{
    int n;
    struct node *a;
    printf("enter total nodes\n");
    scanf("%d", &n);
    create(n);
    a = reverse(4);
    display();
    return 0;
}