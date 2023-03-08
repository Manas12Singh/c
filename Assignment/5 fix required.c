#include <stdio.h>

int main()
{
    char s1[300], s2[300];
    int i = 0, j = 0, flag = 1;
    puts("Enter the string:");
    gets(s1);
    while (s1[i] != '\0')
    {
        if (flag)
        {
            if (s1[i] == 'a' || s1[i] == 'A')
            {
                if (s1[i + 1] == ' ')
                    i++;
                else if (s1[i + 1] == '\0')
                    break;
                else if (s1[i + 1] == 'n')
                {
                    if (s1[i + 2] == ' ')
                        i += 2;
                    else if (s1[i + 2] == '\0')
                        break;
                }
            }
            else if (s1[i] == 't' || s1[i] == 'T')
            {
                if (s1[i + 1] == 'h')
                    if (s1[i + 2] == 'e')
                    {
                        if (s1[i + 3] == ' ')
                            i += 3;
                        else if (s1[i + 3] == '\0')
                            break;
                    }
            }
        }
        s2[j] = s1[i], j++;
        if (s1[i] == ' ')
            flag = 1;
        else
            flag = 0;
        i++;
    }
    s2[j] = '\0';
    puts("Formatted string:");
    puts(s2);
    return 0;
}