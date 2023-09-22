#include <stdio.h>

int main()
{
    char s1[100], s2[100];
    gets(s1);
    gets(s2);
    int i = 0, j, k = 0;
    while (s1[i] != '\0')
    {
        s1[i] = s1[i + k];
        j = 0;
        while (s1[i + j] == s2[j] && s2[j] != '\0')
            j++;
        if (s2[j] == '\0')
            k += j;
        else
            i++;
    }
    puts(s1);
    return 0;
}
