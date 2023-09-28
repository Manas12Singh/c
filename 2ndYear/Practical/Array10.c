#include <stdio.h>
#include <stdlib.h>

int precedence(char c)
{
    switch (c)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
}

char *infixToPostfix(char *infix)
{
    char stack[100];
    char *postfix = (char *)malloc(100);
    int i = 0, size = 0, stackSize = -1;
    while (infix[i] != '\0')
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            while (infix[i] >= '0' && infix[i] <= '9')
                postfix[size++] = infix[i++];
            postfix[size++] = ' ';
        }
        else if (infix[i] == '(')
            stack[++stackSize] = infix[i++];
        else if (infix[i] == ')')
        {
            while (stackSize != -1 && stack[stackSize] != '(')
                postfix[size++] = stack[stackSize--],
                postfix[size++] = ' ';
            stackSize--;
            i++;
        }
        else
        {
            while (stackSize != -1 && precedence(stack[stackSize]) >= precedence(infix[i]))
                postfix[size++] = stack[stackSize--],
                postfix[size++] = ' ';
            stack[++stackSize] = infix[i++];
        }
    }
    while (stackSize != -1)
        postfix[size++] = stack[stackSize--],
        postfix[size++] = ' ';
    postfix[--size] = '\0';
    return postfix;
}

int main()
{
    char infix[100], *postfix;
    printf("Enter the expression: ");
    scanf("%s", infix);
    postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    free(postfix);
}