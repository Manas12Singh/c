#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void printList(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", (*ptr).data);
        ptr = (*ptr).next;
    }
}

struct node *insertionListAtBegin(struct node *ptr)
{
    struct node *temp = (struct node *)calloc(sizeof(struct node), 1);
    (*temp).data = 7;
    (*temp).next = ptr;
    return temp;
}

void insertionList(struct node *ptr, unsigned index)
{
    unsigned i = 0;
    while (i != index - 1)
    {
        ptr = (*ptr).next;
        i++;
    }
    struct node *temp = (struct node *)calloc(sizeof(struct node), 1);
    (*temp).data = 8;
    (*temp).next = (*ptr).next;
    (*ptr).next = temp;
}

int main()
{
    struct node *head;
    struct node *second;
    struct node *third;
    struct node *fourth;

    head = (struct node *)calloc(sizeof(struct node), 1);
    second = (struct node *)calloc(sizeof(struct node), 1);
    third = (struct node *)calloc(sizeof(struct node), 1);
    fourth = (struct node *)calloc(sizeof(struct node), 1);

    (*head).data = 2;
    (*head).next = second;

    (*second).data = 7;
    (*second).next = third;

    (*third).data = 0;
    (*third).next = fourth;

    (*fourth).data = 4;

    printList(head);

    insertionList(head,7);

    printList(head);

    return 0;
}