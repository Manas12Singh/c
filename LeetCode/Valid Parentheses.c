#include <stdbool.h>
#include <string.h>
#include <stdio.h>

bool isValid(char *s)
{
    int l = strlen(s);
    if (l % 2 != 0)
        return false;
    int i = 0, j, c = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '(')
        {
            s[i] = '0';
            j = i + 1;
            while (j < l)
            {
                if (s[j] == ')')
                {
                    s[j] = '0';
                    c++;
                    break;
                }
                j += 2;
            }
        }
        if (s[i] == '{')
        {
            s[i] = '0';
            j = i + 1;
            while (j < l)
            {
                if (s[j] == '}')
                {
                    s[j] = '0';
                    c++;
                    break;
                }
                j += 2;
            }
        }
        if (s[i] == '[')
        {
            s[i] = '0';
            j = i + 1;
            while (j < l)
            {
                if (s[j] == ']')
                {
                    s[j] = '0';
                    c++;
                    break;
                }
                j += 2;
            }
        }
        i++;
    }
    if (c == l / 2)
        return true;
    return false;
}

int main()
{
    char s[10] = "({})()";
    char *s1 = s;
    printf("%d", isValid(s1));
    return 0;
}
