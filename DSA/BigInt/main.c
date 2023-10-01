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
    BigInteger *sum = addBigInteger(b1, b2);
    printBigInteger(sum);
    printf("%d\n", compareBigInteger(b1, b2));
    BigInteger *diff = subtractBigInteger(b1, b2);
    printBigInteger(diff);
    // deleteBigInteger(&b1);
    // deleteBigInteger(&b2);
    // deleteBigInteger(&sum);
    // deleteBigInteger(&diff);
}