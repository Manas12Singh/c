#include <stdio.h>
#include <string.h>

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
            if (strncmp("a ", strlwr(s1 + i), 2) == 0)
            {
                i += 2;
                continue;
            }
            else if (strncmp("an ", strlwr(s1 + i), 3) == 0)
            {
                i += 3;
                continue;
            }
            else if (strncmp("the ", strlwr(s1 + i), 4) == 0)
            {
                i += 4;
                continue;
            }
        }
        if (s1[i] == ' ')
            flag = 1;
        else
            flag = 0;
        s2[j] = s1[i];
        i++, j++;
    }
    s2[j] = '\0';
    puts("Formatted string:");
    puts(s2);
    return 0;
}
