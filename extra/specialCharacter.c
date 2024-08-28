#include <stdio.h>

void spcChar(char s1[]);

int main()
{
    char s1[100];
    gets(s1);
    spcChar(s1);
    return 0;
}

void spcChar(char s1[])
{
    int i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] >= 'A' && s1[i] <= 'Z')
            ;
        else if (s1[i] >= 'a' && s1[i] <= 'z')
            ;
        else if (s1[i] >= '0' && s1[i] <= '9')
            ;
        else
            printf("%c", s1[i]);
        i++;
    }
}
