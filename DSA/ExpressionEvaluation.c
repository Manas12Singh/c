#include <stdio.h>
#include "infixToPostfix.h"

int main()
{
    int r;
    char *infix = "a+b*(c*d-e)-(f+g*h)-i";
    char *postfix = infixToPostfix(infix, strlen(infix), &r);
    for (int i = 0; i < r; i++)
        printf("%c", postfix[i]);
    free(postfix);
}