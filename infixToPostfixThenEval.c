#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    int top;
    int *num;
    char *op;
};

int preced(char c)
{
    switch (c)
    {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '/':
    case '*':
        return 2;
    }
}

void pushNum(struct stack *s1, int n)
{
    s1->num[++(s1->top)] = n;
}

void pushOp(struct stack *s1, char c)
{
    s1->op[++(s1->top)] = c;
}

int popNum(struct stack *s1)
{
    int n = s1->num[(s1->top)--];
    return n;
}

char popOp(struct stack *s1)
{
    char c = s1->op[(s1->top)--];
    return c;
}

char *infixToPostfix(char *s)
{
    struct stack *s1 = (struct stack *)calloc(sizeof(struct stack), 1);
    s1->op = (char *)calloc(sizeof(char), strlen(s) * 2);
    s1->top = -1;
    char c;
    int i = 0, j = 0;
    char *t = (char *)malloc(strlen(s) * 2);
    while (s[i] != '\0')
    {
        while (s[i] >= '0' && s[i] <= '9')
            t[j++] = s[i++];
        t[j++] = ' ';
        if (s[i] == '(')
            pushOp(s1, s[i++]);
        else if (s[i] == ')')
        {
            do
            {
                c = popOp(s1);
                t[j++] = c;
                t[j++] = ' ';
            } while (c != '(');
            j -= 2;
            i++;
        }
        else
        {
            while (s1->top != -1 && (preced(s1->op[s1->top]) >= preced(s[i])))
                t[j++] = popOp(s1), t[j++] = ' ';
            pushOp(s1, s[i++]);
        }
    }
    while (s1->top != -1)
        t[j++] = popOp(s1);
    t[j] = '\0';
    free(s1->op);
    free(s1);
    return t;
}

int postfixEvaluate(char *s)
{
    struct stack *s1 = (struct stack *)calloc(sizeof(struct stack), 1);
    s1->num = (int *)calloc(sizeof(int), strlen(s));
    s1->top = -1;
    int i = 0, n = 0;
    while (s[i] != '\0')
    {
        if (s[i] == ' ')
            i++;
        else if (s[i] >= '0' && s[i] <= '9')
        {
            while (s[i] >= '0' && s[i] <= '9')
                n = n * 10 + s[i] - '0', i++;
            if (n != 0)
                pushNum(s1, n), n = 0;
        }
        else
        {
            int a = popNum(s1);
            int b = popNum(s1);
            switch (s[i])
            {
            case '+':
                pushNum(s1, b + a);
                break;
            case '-':
                pushNum(s1, b - a);
                break;
            case '*':
                pushNum(s1, b * a);
                break;
            case '/':
                pushNum(s1, b / a);
                break;
            }
            i++;
        }
    }
    int res = popNum(s1);
    free(s1->num);
    free(s1);
    return res;
}

int main()
{
    char s[200];
    scanf("%s", s);
    char *t = infixToPostfix(s);
    printf("%s\n", t);
    int n = postfixEvaluate(t);
    printf("%d\n", n);
    free(t);
}
