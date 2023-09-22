#include <stdio.h>

char *convertCase(char s1[]);

int main()
{
    char s1[200];
    puts("Enter the String:");
    gets(s1);
    char *s2 = convertCase(s1);
    puts("Formatted String:");
    puts(s2);
    return 0;
}

char *convertCase(char s1[])
{
    int i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] += 32;
        else if (s1[i] >= 'a' && s1[i] <= 'z')
            s1[i] -= 32;
        i++;
    }
    return s1;
}