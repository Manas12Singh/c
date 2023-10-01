#include "BigInteger.h"

BigInteger *toBigInteger(char *s)
{
    BigInteger *temp = (BigInteger *)malloc(sizeof(BigInteger));
    temp->head = NULL;
    int i = 0;
    if (s[i] == '-')
        temp->sign = -1, i++;
    else if (s[i] == '+')
        temp->sign = 1, i++;
    else
        temp->sign = 1;
    while (s[i] != '\0')
    {
        struct Node *node = (struct Node *)malloc(sizeof(struct Node));
        node->digit = s[i] - '0';
        node->next = temp->head;
        temp->head = node;
        i++;
    }
    return temp;
}

void printNode(struct Node *node)
{
    if (node == NULL)
        return;
    printNode(node->next);
    printf("%d", node->digit);
}

void printBigInteger(BigInteger *b)
{
    if (b == NULL)
    {
        printf("No number saved.");
        return;
    }
    printf("Integer is: ");
    if (b->sign == -1)
        printf("%c", '-');
    printNode(b->head);
    printf("\n");
}

BigInteger *add(BigInteger *b1, BigInteger *b2)
{
    BigInteger *sum = (BigInteger *)malloc(sizeof(BigInteger));
    sum->head = NULL;
    sum->sign = b1->sign;
    struct Node *trav = NULL;
    struct Node *t1 = b1->head, *t2 = b2->head;
    int carry = 0;
    while (t1 || t2 || carry)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->digit = carry;
        temp->next = NULL;
        if (t1)
        {
            temp->digit += t1->digit;
            t1 = t1->next;
        }
        if (t2)
        {
            temp->digit += t2->digit;
            t2 = t2->next;
        }
        carry = temp->digit / 10;
        temp->digit %= 10;
        if (!(sum->head))
            sum->head = trav = temp;
        else
        {
            trav->next = temp;
            trav = trav->next;
        }
    }
    return sum;
}

void removeZeroes(struct Node **head)
{
    if (*head == NULL)
        return;
    if ((*head)->next != NULL)
        removeZeroes(&((*head)->next));
    if ((*head)->digit == 0 && (*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
    }
}

BigInteger *sub(BigInteger *b1, BigInteger *b2)
{
    BigInteger *diff = (BigInteger *)malloc(sizeof(BigInteger));
    diff->head = NULL;
    diff->sign = b1->sign;
    struct Node *trav = NULL;
    struct Node *t1 = b1->head, *t2 = b2->head;
    int borrow = 0;
    while (t1 || t2)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->digit = borrow;
        temp->next = NULL;
        if (t1)
        {
            temp->digit += t1->digit;
            t1 = t1->next;
        }
        if (t2)
        {
            temp->digit -= t2->digit;
            t2 = t2->next;
        }
        if (temp->digit < 0)
            borrow = -1, temp->digit += 10;
        else
            borrow = 0;
        if (!(diff->head))
            diff->head = trav = temp;
        else
        {
            trav->next = temp;
            trav = trav->next;
        }
    }
    removeZeroes(&(diff->head->next));
    if (diff->head->digit == 0 && diff->head->next == NULL)
        diff->sign = 1;
    return diff;
}

int lencompare(struct Node *b1, struct Node *b2)
{
    int len1 = 0, len2 = 0;
    while (b1)
        len1++, b1 = b1->next;
    while (b2)
        len2++, b2 = b2->next;
    if (len1 > len2)
        return 1;
    else if (len2 > len1)
        return -1;
    else
        return 0;
}

int compare(struct Node *b1, struct Node *b2)
{
    if (b1 == NULL)
        return 0;
    int c = compare(b1->next, b2->next);
    if (c == 0)
    {
        if (b1->digit > b2->digit)
            c = 1;
        else if (b1->digit < b2->digit)
            c = -1;
    }
    return c;
}

int compareBigInteger(BigInteger *b1, BigInteger *b2)
{
    if (b1->sign != b2->sign)
        return b1->sign;
    int comp = lencompare(b1->head, b2->head);
    if (comp != 0)
        return comp;
    return compare(b1->head, b2->head);
}

BigInteger *addBigInteger(BigInteger *b1, BigInteger *b2)
{
    if (b1->sign == b2->sign)
        return add(b1, b2);
    int l = lencompare(b1->head, b2->head);
    if (l == 1)
        return sub(b1, b2);
    else if (l == -1)
        return sub(b2, b1);
    else if (compare(b1->head, b2->head) >= 0)
        return sub(b1, b2);
    else
        return sub(b2, b1);
}

BigInteger *subtractBigInteger(BigInteger *b1, BigInteger *b2)
{
    if (b1->sign != b2->sign)
        return add(b1, b2);
    int l = lencompare(b1->head, b2->head);
    BigInteger *diff;
    if (l == 1)
        diff = sub(b1, b2);
    else if (l == -1)
        diff = sub(b2, b1), diff->sign = -(b2->sign);
    else if (compare(b1->head, b2->head) >= 0)
        diff = sub(b1, b2);
    else
        diff = sub(b2, b1), diff->sign = -(b2->sign);
    return diff;
}