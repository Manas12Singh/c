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

