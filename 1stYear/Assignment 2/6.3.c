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
    int f1, f2, i = 0, j1, k1, j2, k2;
    char ch;
    while (*(p1 + i) != '\0')
    {
        ch = *(p1 + i);
        j1 = 0, k1 = 0, f1 = 0;
        j2 = 0, k2 = 0, f2 = 0;
        while (*(p1 + j1) != '\0')
        {
            *(p1 + j1) = *(p1 + k1 + j1);
            *(p2 + j2) = *(p2 + k2 + j2);
            if (*(p1 + j1) == ch)
                k1++, f1++;
            else
                j1++;
            if (*(p2 + j2) == ch)
                k2++, f2++;
            else
                j2++;
        }
        if (f1 != f2)
            return 0;
        i++;
    }
    return 1;
}