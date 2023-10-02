#include <stdio.h>
#include "BigInteger.h"

int main()
{
    char s1[100], s2[100];
    scanf("%s %s", s1, s2);
    BigInteger *b1 = toBigInteger(s1);
    BigInteger *b2 = toBigInteger(s2);
    printBigInteger(b1);
    printBigInteger(b2);
    BigInteger *divide = divideBigIntger(b1, b2);
    printBigInteger(divide);
    printBigInteger(b1);
    printBigInteger(b2);
}