#include <stdio.h>
#include <string.h>

int main()
{
    char s1[200], c1;
    char *s = s1;
    gets(s1);
    int n = strlen(s1) - 1, i = 0;
    while (i < n)
    {
        c1 = *(s + i);
        *(s + i) = *(s + n);
        *(s + n) = c1;
        i++, n--;
    }
    puts(s1);
    return 0;
}
