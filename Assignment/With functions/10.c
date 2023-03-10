#include <stdio.h>

char *removeSpace(char s1[]);

int main()
{
    char s1[200];
    puts("Enter the string: ");
    gets(s1);
    char *s2 = removeSpace(s1);
    puts("Modified string");
    puts(s2);
    return 0;
}

char *removeSpace(char s1[])
{
    int i = 0, j = 0;
    while (s1[i] != '\0')
    {
        s1[i] = s1[i + j];
        if (s1[i] == ' ')
            j++;
        else
            i++;
    }
    return s1;
}