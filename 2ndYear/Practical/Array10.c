#include <stdio.h>
#include <stdlib.h>

int postfixEvaluation(char *);
char *infixToPostfix(char *);
int precedence(char);

int main()
{
    char infix[100], *postfix;
    printf("Enter the expression: ");
    scanf("%s", infix);
    postfix = infixToPostfix(infix);
    printf("%s\n", postfix);
    printf("%d\n", postfixEvaluation(postfix));
    free(postfix);
}

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

int postfixEvaluation(char *s)
{
    int eval[100] = {0}, i = 0, size = -1;
    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            size++;
            int n = 0;
            while (s[i] >= '0' && s[i] <= '9')
                n = n * 10 + (s[i++] - '0');
            eval[size] = n;
        }
        else
        {
            switch (s[i++])
            {
            case '+':
                eval[size - 1] += eval[size];
                size--;
                break;
            case '-':
                eval[size - 1] -= eval[size];
                size--;
                break;
            case '/':
                eval[size - 1] /= eval[size];
                size--;
                break;
            case '*':
                eval[size - 1] *= eval[size];
                size--;
                break;
            }
        }
    }
    return eval[0];
}