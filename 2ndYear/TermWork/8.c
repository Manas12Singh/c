/* 8. Write a program to add of two polynomials of degree n, using linked list.

Name: Manas Singh
Section: C1
Roll No: 38
Course: B.Tech CSE
*/

#include <stdio.h>
#include <stdlib.h>
typedef struct ListNode
{
    int data, power;
    struct ListNode *next;
} ListNode;
ListNode *createNode(int data, int power)
{
    ListNode *temp = (ListNode *)malloc(sizeof(ListNode));
    if (temp == NULL)
    {
        printf("Memory full!\n");
        return NULL;
    }
    temp->data = data;
    temp->power = power;
    temp->next = NULL;
    return temp;
}
ListNode *createList()
{
    int n;
    printf("Enter the degree of the polynomial: ");
    scanf("%d", &n);
    if (n < 0)
    {
        printf("Invalid degree.\n");
        return NULL;
    }
    ListNode *head = NULL, *trav = NULL;
    printf("Enter the values(from highest degree): ");
    while (n > -1)
    {
        int k;
        scanf("%d", &k);
        if (k == 0)
        {
            n--;
            continue;
        }
        ListNode *temp = createNode(k, n);
        if (temp == NULL)
            break;
        if (head == NULL)
            head = trav = temp;
        else
        {
            trav->next = temp;
            trav = temp;
        }
        n--;
    }
    return head;
}
void displayList(ListNode *head)
{
    while (head != NULL)
    {
        printf(" %+dx^%d", head->data, head->power);
        head = head->next;
    }
    printf("\n");
}
ListNode *addPolynomial(ListNode *head1, ListNode *head2)
{
    ListNode *temp = NULL;
    if (head1 == NULL && head2 == NULL)
        return temp;
    if (head2 == NULL)
    {
        temp = createNode(head1->data, head1->power);
        temp->next = addPolynomial(head1->next, head2);
    }
    else if (head1 == NULL)
    {
        temp = createNode(head2->data, head2->power);
        temp->next = addPolynomial(head1, head2->next);
    }
    else if (head1->power > head2->power)
    {
        temp = createNode(head1->data, head1->power);
        temp->next = addPolynomial(head1->next, head2);
    }
    else if (head1->power < head2->power)
    {
        temp = createNode(head2->data, head2->power);
        temp->next = addPolynomial(head1, head2->next);
    }
    else if (head1->data + head2->data == 0)
        temp = addPolynomial(head1->next, head2->next);
    else
    {
        temp = createNode(head1->data + head2->data, head1->power);
        temp->next = addPolynomial(head1->next, head2->next);
    }
    return temp;
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
    ListNode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    int opt;
    do
    {
        printf("1. Create polynomial 1\n2. Create polynomial 2\n3. Add polynomials\n4. Display polynomials\n5. Exit\nEnter your choice: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            if (p1 != NULL)
                freeList(&p1);
            p1 = createList();
            break;
        case 2:
            if (p2 != NULL)
                freeList(&p2);
            p2 = createList();
            break;
        case 3:
            if (p3 != NULL)
                freeList(&p3);
            p3 = addPolynomial(p1, p2);
            break;
        case 4:
            printf("Polynomial 1: ");
            displayList(p1);
            printf("Polynomial 2: ");
            displayList(p2);
            printf("Polynomial 3: ");
            displayList(p3);
            break;
        case 5:
            break;
        default:
            printf("Invalid choice.\n");
        }
    } while (opt != 5);
    freeList(&p1);
    freeList(&p2);
    freeList(&p3);
}

/*
Output:
1. Create polynomial 1
2. Create polynomial 2
3. Add polynomials
4. Display polynomials
5. Exit
Enter your choice: 1
Enter the degree of the polynomial: 4
Enter the values(from highest degree): 1 -2 3 0 -4
1. Create polynomial 1
2. Create polynomial 2
3. Add polynomials
4. Display polynomials
5. Exit
Enter your choice: 2
Enter the degree of the polynomial: 3
Enter the values(from highest degree): 2 -3 4 0
1. Create polynomial 1
2. Create polynomial 2
3. Add polynomials
4. Display polynomials
5. Exit
Enter your choice: 3
1. Create polynomial 1
2. Create polynomial 2
3. Add polynomials
4. Display polynomials
5. Exit
Enter your choice: 4
Polynomial 1:  +1x^4 -2x^3 +3x^2 -4x^0
Polynomial 2:  +2x^3 -3x^2 +4x^1
Polynomial 3:  +1x^4 +4x^1 -4x^0
1. Create polynomial 1
2. Create polynomial 2
3. Add polynomials
4. Display polynomials
5. Exit
Enter your choice: 5
*/