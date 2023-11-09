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

typedef struct node
{
    short digit;
    struct node *next;
} Digit;

typedef struct
{
    int sign;
    Digit *lastDigit;
} BigInteger;

BigInteger *toBigInteger(char *string);
void printBigInteger(BigInteger *bigInt);
int compareBigInteger(BigInteger *bigInt1, BigInteger *bigInt2);
BigInteger *addBigInteger(BigInteger *bigInt1, BigInteger *bigInt2);
BigInteger *subtractBigInteger(BigInteger *bigInt1, BigInteger *bigInt2);
BigInteger *multiplyBigInteger(BigInteger *bigInt1, BigInteger *bigInt2);
BigInteger *divideBigInteger(BigInteger *bigInt1, BigInteger *bigInt2);
BigInteger *modulusBigInteger(BigInteger *bigInt1, BigInteger *bigInt2);
void deleteBigInteger(BigInteger **bigInt);
#endif