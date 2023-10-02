#include <stdio.h>
#include "BigInteger.h"

BigInteger *factorial(BigInteger *n)
{
    if (compareBigInteger(n, toBigInteger("1")) == 0 || compareBigInteger(n, toBigInteger("1")) == 0)
        return toBigInteger("1");
    return multiplyBigIntger(n, factorial(subtractBigInteger(n, toBigInteger("1"))));
}

int main()
{
}