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

BigInteger *toBigInteger(char *);
void printBigInteger(BigInteger *);
int compareBigInteger(BigInteger *, BigInteger *);
BigInteger *addBigInteger(BigInteger *, BigInteger *);
BigInteger *subtractBigInteger(BigInteger *, BigInteger *);
BigInteger *multiplyBigIntger(BigInteger *, BigInteger *);
BigInteger *divideBigIntger(BigInteger *, BigInteger *);
void deleteBigInteger(BigInteger **);
#endif