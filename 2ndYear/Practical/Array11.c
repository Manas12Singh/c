#include <stdio.h>

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

int main()
{
    char postfix[100];
    printf("Enter the expression: ");
    fgets(postfix, 100, stdin);
    printf("%d\n", postfixEvaluation(postfix));
}