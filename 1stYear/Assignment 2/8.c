#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *consonant(char *p1);

int main()
{
    char s1[200];
    char *p1 = s1;
    gets(s1);
    char *s2 = consonant(p1);
    printf("Cosonants: %s\n", s2);
    free(s2);
    return 0;
}

char *consonant(char *p1)
{
    char *s2 = calloc(strlen(p1), sizeof(char));
    int i = 0;
    while (*p1 != '\0')
    {
        if (isalpha(*p1))
        {
            switch (*p1)
            {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                break;
            default:
                *(s2 + i++) = *p1;
            }
        }
        p1++;
    }
    *(s2 + i) = '\0';
    return s2;
}