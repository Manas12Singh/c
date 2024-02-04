#include <stdio.h>
#include "BigInteger.h"

int main()
{
    BigInteger *fact = toBigInteger("1");
    BigInteger *i = toBigInteger("1");
    BigInteger *one = toBigInteger("1");
    BigInteger *n = toBigInteger("15000");
    while (compareBigInteger(i, n) < 1)
    {
        fact = multiplyBigIntger(fact, i);
        i = addBigInteger(i, one);
    }
    printBigInteger(fact);
}