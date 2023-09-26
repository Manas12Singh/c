#ifndef STDLIB_H
#include <stdlib.h>
#endif

#ifndef STDIO_H
#include <stdio.h>
#endif

#ifndef STRING_H
#include <string.h>
#endif

#ifndef BIGINTEGER_H
#define BIGINTEGER_H

struct Node
{
    int digit;
    struct Node *next;
};

typedef struct
{
    int sign;
    struct Node *head;
} BigInteger;

BigInteger *getInt(char *);
void printInt(BigInteger *);
static void printNode(struct Node *);
BigInteger *add(BigInteger *, BigInteger *);
BigInteger *subtract(BigInteger *, BigInteger *);
BigInteger *multiply(BigInteger *, BigInteger *);
BigInteger *divide(BigInteger *, BigInteger *);
void deleteInt(BigInteger **);
#endif