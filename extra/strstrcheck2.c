#include <stdio.h>

int main()
{
    char s1[200], s2[200];
    gets(s1);
    gets(s2);
    int i = 0, j, flag = 0;
    while (s1[i] != '\0')
    {
        j = 0;
        while (s1[i + j] == s2[j] && s2[j] != '\0')
            j++;
        if (s2[j] == '\0')
        {
            flag = 1;
            break;
        }
        i++;
    }
    if (flag == 1)
        printf("Substring found");
    else
        printf("Not found");
    return 0;
}
