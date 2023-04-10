#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    return (*(char *)a) - (*(char *)b);
}

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
    qsort(p1, strlen(p1), sizeof(char), cmp);
    qsort(p2, strlen(p2), sizeof(char), cmp);
    while (*p1 != '\0')
    {
        if (*p1 != *p2)
            return 0;
        p1++, p2++;
    }
    return 1;
}