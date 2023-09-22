#include <stdio.h>

int main()
{
    char s1[200], ch;
    int f, i = 0, j, k;
    gets(s1);
    while (s1[i] != '\0')
    {
        ch = s1[i];
        j = i + 1, k = 0, f = 1;
        while (s1[j] != '\0')
        {
            s1[j] = s1[k + j];
            if (s1[j] == ch)
                k++, f++;
            else
                j++;
        }
        printf("%c: %d\n", ch, f);
        i++;
    }
    return 0;
}