#include <stdio.h>

int main()
{
    char s1[200], s2[200];
    gets(s1);
    gets(s2);
    int i = 0, j, m, flag = 0;
    while (s1[i] != '\0')
    {
        j = 0, m = i;
        while (s2[j] != '\0')
        {
            if (s1[i] == s2[j]) // line fixed
            {
                flag = 1;
                i++;
                j++;
            }
            else
            {
                flag = 0;
                break;          // line added
            }
        }
        if (flag == 1)
        {
            printf("Substring found");
            break;
        }
        else
        {
            i = m + 1;
        }
    }
    if (flag != 1)
        printf("Not found");
    return 0;
}
