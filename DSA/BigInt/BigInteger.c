#include "BigInteger.h"

BigInteger *toBigInteger(char *s)
{
    if (strlen(s) == 0)
        return NULL;
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
    if (b->sign == -1)
        printf("%c", '-');
    printNode(b->head);
    printf("\n");
}

void freeNode(struct Node **node)
{
    if (*node == NULL)
        return;
    freeNode(&((*node)->next));
    free(*node);
    *node = NULL;
}

void deleteBigInteger(BigInteger **b)
{
    if (*b == NULL)
        return;
    freeNode(&((*b)->head));
    free(*b);
    *b = NULL;
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

BigInteger *add(BigInteger *b1, BigInteger *b2)
{
    if (b1 == NULL || b2 == NULL)
        return NULL;
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

BigInteger *sub(BigInteger *b1, BigInteger *b2)
{
    if (b1 == NULL || b2 == NULL)
        return NULL;
    BigInteger *diff = (BigInteger *)malloc(sizeof(BigInteger));
    diff->head = NULL;
    diff->sign = b1->sign;
    struct Node *trav = NULL;
    struct Node *t1 = b1->head, *t2 = b2->head;
    int borrow = 0;
    while (t1 || t2)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->digit = borrow + t1->digit;
        temp->next = NULL;
        t1 = t1->next;
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
    if (b1 == NULL || b2 == NULL)
        return NULL;
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
    if (b1 == NULL || b2 == NULL)
        return NULL;
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

BigInteger *multiplyBigIntger(BigInteger *b1, BigInteger *b2)
{
    if (b1 == NULL || b2 == NULL)
        return NULL;
    if (lencompare(b1->head, b2->head) == -1)
    {
        BigInteger *temp = b1;
        b1 = b2;
        b2 = temp;
    }
    BigInteger *product = (BigInteger *)malloc(sizeof(BigInteger));
    product->sign = (b1->sign == b2->sign) ? 1 : -1;
    product->head = NULL;
    struct Node *t2 = b2->head;
    struct Node *head = NULL, *t = NULL;
    int n = 0;
    while (t2)
    {
        struct Node *t1 = b1->head, *trav = product->head;
        int carry = 0;
        int i = n;
        while (trav || t1 || carry)
        {
            struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
            temp->digit = carry;
            temp->next = NULL;
            if (trav)
            {
                temp->digit += trav->digit;
                trav = trav->next;
            }
            if (i-- <= 0 && t1)
            {
                temp->digit += t1->digit * t2->digit;
                t1 = t1->next;
            }
            carry = temp->digit / 10;
            temp->digit %= 10;
            if (head)
            {
                t->next = temp;
                t = t->next;
            }
            else
                head = t = temp;
        }
        freeNode(&(product->head));
        product->head = head;
        head = t = NULL;
        t2 = t2->next;
        n++;
    }
    return product;
}

struct Node *divide(struct Node *n1, struct Node *n2, BigInteger *q)
{
    if (n1 == NULL)
        return NULL;
    n1->next = divide(n1->next, n2, q);
    if (q)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->digit = 0;
        temp->next = q->head;
        q->head = temp;
    }
    if (lencompare(n1, n2) == -1 || (lencompare(n1, n2) == 0 && compare(n1, n2) == -1))
        return n1;
    while (lencompare(n1, n2) == 1 || (lencompare(n1, n2) == 0 && compare(n1, n2) >= 0))
    {
        struct Node *t1 = n1, *t2 = n2;
        int borrow = 0;
        while (t2 || borrow)
        {
            t1->digit -= borrow;
            if (t2)
            {
                t1->digit -= t2->digit;
                t2 = t2->next;
            }
            if (t1->digit < 0)
            {
                borrow = 1;
                t1->digit += 10;
            }
            else
                borrow = 0;
            t1 = t1->next;
        }
        removeZeroes(&n1);
        if (q)
            q->head->digit++;
    }
    return n1;
}

BigInteger *divideBigIntger(BigInteger *b1, BigInteger *b2)
{
    if (b1 == NULL || b2 == NULL)
        return NULL;
    BigInteger *quotient = (BigInteger *)malloc(sizeof(BigInteger));
    quotient->sign = (b1->sign == b2->sign) ? 1 : -1;
    quotient->head = NULL;
    struct Node *dividend = NULL, *t1, *t2 = b1->head;
    while (t2)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->digit = t2->digit;
        temp->next = NULL;
        if (dividend)
        {
            t1->next = temp;
            t1 = t1->next;
        }
        else
            dividend = t1 = temp;
        t2 = t2->next;
    }
    divide(dividend, b2->head, quotient);
    removeZeroes(&(quotient->head));
    if (quotient->head == NULL)
    {
        quotient->sign = 1;
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->digit = 0;
        temp->next = NULL;
        quotient->head = temp;
    }
    return quotient;
}

BigInteger *modulusBigInteger(BigInteger *b1, BigInteger *b2)
{
    if (b1 == NULL || b2 == NULL)
        return NULL;
    BigInteger *mod = (BigInteger *)malloc(sizeof(BigInteger));
    mod->sign = b1->sign;
    mod->head = NULL;
    struct Node *dividend = NULL, *t1, *t2 = b1->head;
    while (t2)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->digit = t2->digit;
        temp->next = NULL;
        if (dividend)
        {
            t1->next = temp;
            t1 = t1->next;
        }
        else
            dividend = t1 = temp;
        t2 = t2->next;
    }
    mod->head = divide(dividend, b2->head, NULL);
    if (mod->head == NULL)
    {
        mod->sign = 1;
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        temp->digit = 0;
        temp->next = NULL;
        mod->head = temp;
    }
    return mod;
}