/* 6. Write a C program to create two link lists positive and negative from Original linked list, so that positive linked list contains all positive elements and negative linked list contains negative elements. Positive and negative linked lists should use the node of existing original linked list.

Name: Manas Singh
Section: C1
Roll No: 38
Course: B.Tech CSE
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;
ListNode *createNode(int data)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    if (temp == NULL)
        printf("Memory full!\n");
    else
    {
        temp->data = data;
        temp->next = NULL;
    }
    return temp;
}
ListNode *createList()
{
    int n;
    printf("Enter the number of node(s): ");
    scanf("%d", &n);
    if (n < 1)
    {
        printf("Invalid number of nodes.\n");
        return NULL;
    }
    ListNode *head = NULL, *trav = NULL;
    printf("Enter the values: ");
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        ListNode *temp = createNode(k);
        if (temp == NULL)
            break;
        if (head == NULL)
            head = trav = temp;
        else
        {
            trav->next = temp;
            trav = temp;
        }
    }
    return head;
}
void convert(ListNode **head, ListNode **positive, ListNode **negative)
{
    ListNode *trav1 = NULL, *trav2 = NULL;
    while ((*head) != NULL)
    {
        if ((*head)->data < 0)
        {
            if (*negative == NULL)
                *negative = trav2 = *head;
            else
            {
                trav2->next = *head;
                trav2 = trav2->next;
            }
        }
        else
        {
            if (*positive == NULL)
                *positive = trav1 = *head;
            else
            {
                trav1->next = *head;
                trav1 = trav1->next;
            }
        }
        *head = (*head)->next;
    }
    if (trav1 != NULL)
        trav1->next = NULL;
    if (trav2 != NULL)
        trav2->next = NULL;
}
void printList(ListNode *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}
void freeList(ListNode **head)
{
    while (*head != NULL)
    {
        ListNode *temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}
int main()
{
    int opt, n;
    ListNode *l1 = NULL, *positive = NULL, *negative = NULL;
    do
    {
        printf("Options:\n1. Create List.\n2. Convert to positive and negative lists.\n3. Print positive.\n4. Print negative.\n5. Exit\n");
        printf("Enter your choice (1 to 5): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            freeList(&l1);
            l1 = createList();
            break;
        case 2:
            freeList(&positive);
            freeList(&negative);
            convert(&l1, &positive, &negative);
            break;
        case 3:
            printList(positive);
            break;
        case 4:
            printList(negative);
            break;
        case 5:
            break;
        default:
            printf("Wrong Choice!\n");
        }
    } while (opt != 5);
    freeList(&l1);
    freeList(&positive);
    freeList(&negative);
    return 0;
}

/*
Output:
Options:
1. Create List.
2. Convert to positive and negative lists.
3. Print positive.
4. Print negative.
5. Exit
Enter your choice (1 to 5): 1
Enter the number of node(s): 10
Enter the values: 1 -1 -2 2 3 4 5 -3 -4 -5
Options:
1. Create List.
2. Convert to positive and negative lists.
3. Print positive.
4. Print negative.
5. Exit
Enter your choice (1 to 5): 2
Options:
1. Create List.
2. Convert to positive and negative lists.
3. Print positive.
4. Print negative.
5. Exit
Enter your choice (1 to 5): 3
1 2 3 4 5
Options:
1. Create List.
2. Convert to positive and negative lists.
3. Print positive.
4. Print negative.
5. Exit
Enter your choice (1 to 5): 4
-1 -2 -3 -4 -5
Options:
1. Create List.
2. Convert to positive and negative lists.
3. Print positive.
4. Print negative.
5. Exit
Enter your choice (1 to 5): 5
*/