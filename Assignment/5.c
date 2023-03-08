#include <stdio.h>

int main()
{
    char s1[300];
    int i = 0, j = 0, flag = 1;
    puts("Enter the string:");
    gets(s1);
    while (s1[i] != '\0')
    {
        if (flag)
        {
            if (s1[i] == 'a' || s1[i] == 'A')
            {
                if (s1[i + 1] == ' ' || s1[i + 1] == '\0')
                {
                    i++;
                    flag=2;
                    continue;
                }
                else if (s1[i + 1] == 'n')
                    if (s1[i + 2] == ' ' || s1[i + 2] == '\0')
                    {
                        i += 2;
                        flag=2;
                        continue;
                    }
            }
            else if (s1[i] == 't' || s1[i] == 'T')
                if (s1[i + 1] == 'h' && s1[i + 2] == 'e')
                    if (s1[i + 3] == ' ' || s1[i + 3] == '\0')
                    {
                        i += 3;
                        flag=2;
                        continue;
                    }
        }
        if(flag==2) i++;
        if (s1[i] == ' ')
            flag = 1;
        else flag=0;
        s1[j]=s1[i];
        i++,j++;
    }
    s1[j] = '\0';
    puts("Formatted string:");
    puts(s1);
    return 0;
}