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

BigInteger *toBigInteger(char *string);
void printBigInteger(BigInteger *bigInt);
int compareBigInteger(BigInteger *bigInt1, BigInteger *bigInt2);
BigInteger *addBigInteger(BigInteger *bigInt1, BigInteger *bigInt2);
BigInteger *subtractBigInteger(BigInteger *bigInt1, BigInteger *bigInt2);
BigInteger *multiplyBigIntger(BigInteger *bigInt1, BigInteger *bigInt2);
BigInteger *divideBigIntger(BigInteger *bigInt1, BigInteger *bigInt2);
BigInteger *modulusBigInteger(BigInteger *bigInt1, BigInteger *bigInt2);
void deleteBigInteger(BigInteger **bigInt);
#endif