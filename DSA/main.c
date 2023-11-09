#include <stdio.h>
#include "BigInteger.h"

int main()
{
    char s1[1000],s2[1000];
    scanf("%s", s1);
	scanf("%s", s2);
	BigInteger *b1=toBigInteger(s1);
	BigInteger *b2=toBigInteger(s2);
    printBigInteger(b1);
	printBigInteger(b2);
	BigInteger *b3= divideBigInteger(b1,b2);
	BigInteger *b4= modulusBigInteger(b1,b2);
	printBigInteger(b4);
	printBigInteger(b3);
	deleteBigInteger(&b4);
	deleteBigInteger(&b3);
}