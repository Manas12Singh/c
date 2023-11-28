#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    short data;
    struct ListNode *next;
} ListNode;

ListNode *createNode(short data)
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

int lencompare(ListNode *n1, ListNode *n2)
{
    int len1 = 0, len2 = 0;
    while (n1 != NULL)
        len1++, n1 = n1->next;
    while (n2 != NULL)
        len2++, n2 = n2->next;
    return len1 - len2;
}

short compare(ListNode *n1, ListNode *n2)
{
    while (n1 != NULL)
    {
        if (n1->data > n2->data)
            return 1;
        if (n1->data < n2->data)
            return -1;
        n1 = n1->next;
        n2 = n2->next;
    }
    return 0;
}

ListNode *sub(ListNode *n1, ListNode *n2, int *borrow)
{
    if (n1 == NULL || n2 == NULL)
        return NULL;
    int b = 0;
    ListNode *temp = createNode(n1->data);
    temp->data -= n2->data;
    temp->next = sub(n1->next, n2->next, &b);
    temp->data -= b;
    if (temp->data < 0)
    {
        temp->data += 10;
        if (borrow != NULL)
            *borrow = 1;
    }
    return temp;
}

ListNode *subtract(ListNode *n1, ListNode *n2)
{
    int len = lencompare(n1, n2);
    if (len == 0 && compare(n1, n2) == -1)
    {
        ListNode *temp = n1;
        n1 = n2;
        n2 = temp;
    }
    while (len-- > 0)
    {
        ListNode *temp = createNode(0);
        temp->next = n2;
        n2 = temp;
    }
    ListNode *diff = sub(n1, n2, NULL);
    return diff;
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
        printf("Options:\n1. Enter in List A.\n2. Enter in List B.\n3. Subtract.\n4. Print lists.\n5. Exit\n");
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
            S = subtract(A, B);
            break;
        case 4:
            printf("List A: ");
            printList(A);
            printf("List B: ");
            printList(B);
            printf("Difference: ");
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