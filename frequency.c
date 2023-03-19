#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return (*(char *)a - *(char *)b);
}

int main()
{
    char s1[200];
    int f = 1, i = 0;
    gets(s1);
    qsort(s1, strlen(s1), sizeof(char), cmp);
    while (s1[i] != '\0')
    {
        if (s1[i] != s1[i + 1])
        {
            printf("%c: %d\n", s1[i], f);
            f = 1;
        }
        else
            f++;
        i++;
    }
    return 0;
}