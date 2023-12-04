/* 2. Let A and B be two structures of type Linked List. Write a ‘C ’ program to create a new Linked List ‘S’ that contains elements alternately from A and B beginning with the first element of A. If you run out of elements in one of the lists, then append the remaining.

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
ListNode *mergeAlternate(ListNode *head1, ListNode *head2)
{
    ListNode *head = NULL, *trav = NULL;
    while (head1 != NULL || head2 != NULL)
    {
        if (head1 != NULL)
        {
            ListNode *temp = head1;
            head1 = head1->next;
            if (head == NULL)
                head = trav = temp;
            else
            {
                trav->next = temp;
                trav = temp;
            }
        }
        if (head2 != NULL)
        {
            ListNode *temp = head2;
            head2 = head2->next;
            if (head == NULL)
                head = trav = temp;
            else
            {
                trav->next = temp;
                trav = temp;
            }
        }
    }
    return head;
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
    int opt;
    ListNode *A = NULL, *B = NULL, *S = NULL;
    do
    {
        printf("Options:\n1. Enter in List A.\n2. Enter in List B.\n3. Merge to S.\n4. Print S.\n5. Exit\n");
        printf("Enter your choice (1 to 5): ");
        scanf("%d%*c", &opt);
        switch (opt)
        {
        case 1:
            if (A != NULL)
                freeList(&A);
            A = createList();
            break;
        case 2:
            if (B != NULL)
                freeList(&B);
            B = createList();
            break;
        case 3:
            if (S != NULL)
                freeList(&S);
            S = mergeAlternate(A, B);
            break;
        case 4:
            printf("List S: ");
            printList(S);
            break;
        case 5:
            break;
        default:
            printf("Wrong Choice!\n");
        }
    } while (opt != 5);
    freeList(&A);
    freeList(&B);
    freeList(&S);
    return 0;
}

/*
Output:
Options:
1. Enter in List A.
2. Enter in List B.
3. Merge to S.
4. Print S.
5. Exit
Enter your choice (1 to 5): 1
Enter the number of node(s): 5
Enter the values: 9 5 2 8 3
Options:
1. Enter in List A.
2. Enter in List B.
3. Merge to S.
4. Print S.
5. Exit
Enter your choice (1 to 5): 2
Enter the number of node(s): 3
Enter the values: 6 8 2
Options:
1. Enter in List A.
2. Enter in List B.
3. Merge to S.
4. Print S.
5. Exit
Enter your choice (1 to 5): 3
Options:
1. Enter in List A.
2. Enter in List B.
3. Merge to S.
4. Print S.
5. Exit
Enter your choice (1 to 5): 4
List S: 9 6 5 8 2 2 8 3
Options:
1. Enter in List A.
2. Enter in List B.
3. Merge to S.
4. Print S.
5. Exit
Enter your choice (1 to 5): 5
*/