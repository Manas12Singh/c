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
    int a1[26] = {0}, a2[26] = {0}, i = 0;
    for (int i = 0; i < strlen(p1); i++)
    {
        int x1 = p1[i] - 'a';
        int x2 = p2[i] - 'a';
        if (x1 >= 0 && x1 < 26)
            a1[x1]++;
        if (x2 >= 0 && x2 < 26)
            a2[x2]++;
    }
    for (int i = 0; i < 26; i++)
        if (a1[i] != a2[i])
            return 0;
    return 1;
}