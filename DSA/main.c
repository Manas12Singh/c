#include <stdio.h>
#include "BigInteger.h"

BigInteger *factorial(BigInteger *n)
{
    if (compareBigInteger(n, toBigInteger("1")) <= 0)
        return n;
    return multiplyBigIntger(n,factorial(subtractBigInteger(n,toBigInteger("1"))));
}

int main()
{
    char s1[100], s2[100];
    scanf("%s", s1);
    printBigInteger(factorial(toBigInteger(s1)));
}