#include <stdio.h>
#include <ctype.h>
int findWord(char s1[], char s2[]);

int main()
{
    char s1[200], s2[200];
    gets(s1);
    gets(s2);
    if (findWord(s1, s2))
        puts("Found.");
    else
        puts("Not found.");
    return 0;
}

int findWord(char s1[], char s2[])
{
    int i = 0, j, flag = 1;
    while (s1[i] != '\0')
    {
        if (flag)
        {
            j = 0;
            while (s1[i] == s2[j])
                j++, i++;
            if ((ispunct(s1[i]) || s1[i] == ' ') && s2[j] == '\0')
                return 1;
        }
        if (ispunct(s1[i]) || s1[i] == ' ')
            flag = 1;
        else
            flag = 0;
        i++;
    }
    return 0;
}