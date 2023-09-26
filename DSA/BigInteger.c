#include "BigInteger.h"

BigInteger *getInt(char *s)
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

void printInt(BigInteger *b)
{
    if (b == NULL)
    {
        printf("No number saved.");
        return;
    }
    printf("Integer is: %c", (b->sign == 1) ? '+' : '-');
    printNode(b->head);
    printf("\n");
}

void printNode(struct Node *node)
{
    if (node == NULL)
        return;
    printNode(node->next);
    printf("%d", node->digit);
}

BigInteger *add(BigInteger *b1, BigInteger *b2)
{
    
}