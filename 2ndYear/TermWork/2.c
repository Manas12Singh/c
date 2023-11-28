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
            ListNode *temp = createNode(head1->data);
            if (temp == NULL)
                break;
            if (head == NULL)
                head = trav = temp;
            else
            {
                trav->next = temp;
                trav = trav->next;
            }
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            ListNode *temp = createNode(head2->data);
            if (temp == NULL)
                break;
            if (head == NULL)
                head = trav = temp;
            else
            {
                trav->next = temp;
                trav = trav->next;
            }
            head2 = head2->next;
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
    while (1)
    {
        printf("Options:\n1. Enter in List A.\n2. Enter in List B.\n3. Merge.\n4. Print lists.\n5. Exit\n");
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
            printf("List A: ");
            printList(A);
            printf("List B: ");
            printList(B);
            printf("List S: ");
            printList(S);
            break;
        case 5:
            freeList(&A);
            freeList(&B);
            freeList(&S);
            return 0;
        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}