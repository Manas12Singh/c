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

void convert(ListNode *head, ListNode **positive, ListNode **negative)
{
    ListNode *head1 = NULL, *head2 = NULL;
    ListNode *trav1, *trav2;
    while (head != NULL)
    {
        if (head->data < 0)
        {
            if (head2 == NULL)
                head2 = trav2 = head;
            else
            {
                trav2->next = head;
                trav2 = trav2->next;
            }
        }
        else
        {
            if (head1 == NULL)
                head1 = trav1 = head;
            else
            {
                trav1->next = head;
                trav1 = trav1->next;
            }
        }
        head = head->next;
    }
    trav1->next = trav2->next = NULL;
    *positive = head1;
    *negative = head2;
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
    ListNode *l1 = NULL, *postitive = NULL, *negative = NULL;
    do
    {
        printf("Options:\n1. Create List.\n2. Convert to positive and negative lists.\n3. Print positive.\n4. Print negative.\n5. Exit\n");
        printf("Enter your choice (1 to 5): ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            l1 = createList();
            break;
        case 2:
            convert(l1, &postitive, &negative);
            break;
        case 3:
            printList(postitive);
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
    freeList(&postitive);
    freeList(&negative);
    return 0;
}