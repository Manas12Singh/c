#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int evaluateExpression(char *expression)
{
    int result = 0;
    int sign = 1;
    int num = 0;
    int i = 0;
    int *stack = NULL;
    int top = -1;

    while (expression[i] != '\0')
    {
        if (isdigit(expression[i]))
        {
            num = 0;
            while (isdigit(expression[i]))
            {
                num = num * 10 + (expression[i] - '0');
                i++;
            }
            result += sign * num;
        }
        else if (expression[i] == '+')
        {
            sign = 1;
            i++;
        }
        else if (expression[i] == '-')
        {
            sign = -1;
            i++;
        }
        else if (expression[i] == '(')
        {
            // Push the current result and sign onto the stack
            stack = (int *)realloc(stack, (top + 2) * sizeof(int));
            stack[++top] = result;
            stack[++top] = sign;
            result = 0;
            sign = 1;
            i++;
        }
        else if (expression[i] == ')')
        {
            // Pop the previous result and sign from the stack
            result = stack[top--] + stack[top--] * result;
            i++;
        }
        else
        {
            // Ignore any other characters
            i++;
        }
    }

    // Free the stack memory
    free(stack);

    return result;
}

int main()
{
    char expression[] = "1+4+(2-3)";
    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}