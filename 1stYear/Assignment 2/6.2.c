#include <stdio.h>
#include <string.h>

int anagram(char *p1, char *p2);

int main()
{
    char s1[200], s2[200];
    char *p1 = s1, *p2 = s2;
    puts("Enter a string-1:");
    gets(s1);
    puts("Enter a string-2:");
    gets(s2);
    int flag = anagram(p1, p2);
    if (flag == 1)
        puts("Both the strings are anagrams of each other.");
    else
        puts("Both the strings are not the anagrams of each other.");
    return 0;
}

int anagram(char *p1, char *p2)
{
    if (strlen(p1) != strlen(p2))
        return 0;
    char ch;
    for (int i = 0; i < strlen(p1); i++)
        for (int j = i + 1; j < strlen(p1); j++)
        {
            if (*(p1 + i) > *(p1 + j))
            {
                ch = *(p1 + i);
                *(p1 + i) = *(p1 + j);
                *(p1 + j) = ch;
            }
            if (*(p2 + i) > *(p2 + j))
            {
                ch = *(p2 + i);
                *(p2 + i) = *(p2 + j);
                *(p2 + j) = ch;
            }
        }
    while (*p1 != '\0')
    {
        if (*p1 != *p2)
            return 0;
        p1++, p2++;
    }
    return 1;
}