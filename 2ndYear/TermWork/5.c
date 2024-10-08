/* 5. Write a C program to craeate a single linked list , like L0 -> L1 -> … -> Ln-1 -> Ln. Write another C fucntion to rearrange the nodes in the list so that the new formed list is : L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2 .You are required to do this in place without altering the nodes’ values.
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
    {
        printf("Memory full!\n");
        return NULL;
    }
    temp->data = data;
    temp->next = NULL;
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
void reorderList(ListNode *head)
{
    if (head->next == NULL || head->next->next == NULL)
        return;
    ListNode *p1 = head, *p2 = head;
    while (p2->next != NULL && p2->next->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    p2 = NULL;
    while (p1->next != NULL)
    {
        ListNode *temp = p1->next;
        p1->next = p1->next->next;
        temp->next = p2;
        p2 = temp;
    }
    p1 = head;
    while (p2 != NULL)
    {
        ListNode *temp = p2;
        p2 = p2->next;
        temp->next = p1->next;
        p1->next = temp;
        p1 = p1->next->next;
    }
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
    ListNode *l1 = NULL;
    do
    {
        printf("Options:\n1. Create List.\n2. Rearrange.\n3. Print list.\n4. Exit\n");
        printf("Enter your choice (1 to 4): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            l1 = createList();
            break;
        case 2:
            reorderList(l1);
            break;
        case 3:
            printf("List: ");
            printList(l1);
            break;
        case 4:
            break;
        default:
            printf("Wrong Choice!\n");
        }
    } while (opt != 4);
    freeList(&l1);
    return 0;
}

/*
Output:
Options:
1. Create List.
2. Rearrange.
3. Print list.
4. Exit
Enter your choice (1 to 4): 1
Enter the number of node(s): 5
Enter the values: 1 2 3 4 5
Options:
1. Create List.
2. Rearrange.
3. Print list.
4. Exit
Enter your choice (1 to 4): 2
Options:
1. Create List.
2. Rearrange.
3. Print list.
4. Exit
Enter your choice (1 to 4): 3
List: 1 5 2 4 3
Options:
1. Create List.
2. Rearrange.
3. Print list.
4. Exit
Enter your choice (1 to 4): 4
*/