void push(char st[], int *top, int n, char ch)
{
    if ((*top) > n - 1)
    {
        return;
    }
    else
    {
        st[++(*top)] = ch;
    }
}

char pop(char st[], int *top)
{
    if ((*top) == -1)
    {
        return 0;
    }
    else
    {
        char t = st[(*top)--];
        return t;
    }
}

char *removeOuterParentheses(char *s)
{
    int i = 0, top = -1, flag = 0;
    char stack[strlen(s)];

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
        {
            if (flag != 0)
            {
                push(stack, &top, strlen(s), '(');
            }
            flag++;
        }
        else if (s[i] == ')')
        {
            flag--;
            if (flag != 0)
            {
                push(stack, &top, strlen(s), ')');
            }
        }
    }

    i = top;
    s[++i] = '\0';
    while (i >= 0)
    {
        s[--i] = pop(stack, &top);
    }

    return s;
}