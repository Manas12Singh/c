#include <stdio.h>
#include <string.h>

char *strConcate(char s1[], char s2[]);

int main()
{
    char s1[200], s2[200];
    puts("Enter first String:");
    gets(s1);
    puts("Enter second String:");
    gets(s2);
    char *s3 = strConcate(s1, s2);
    puts("Concated string:");
    puts(s3);
    return 0;
}

char *strConcate(char s1[], char s2[])
{
    int i, j = 0;
    i = strlen(s1);
    s1[i] = ' ';
    i++;
    while (s2[j] != '\0')
    {
        s1[i] = s2[j];
        i++, j++;
    }
    s1[i] = '\0';
    return s1;
}