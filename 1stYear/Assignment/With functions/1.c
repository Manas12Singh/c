#include <stdio.h>
#include <string.h>

char *reverse(char s1[]);

int main()
{
    int flag;
    char s1[200];
    puts("Enter the string: ");
    gets(s1);
    char *s2 = reverse(s1);
    flag = strcmp(s1, s2);
    if (flag == 0)
        puts("Palindrome");
    else
        puts("Not a Palindrome");
    return 0;
}

char *reverse(char s1[])
{
    static char s2[200];
    int l, i = 0;
    l = strlen(s1) - 1;
    while (l >= 0)
    {
        s2[i] = s1[l];
        i++;
        l--;
    }
    s2[i] = '\0';
    return s2;
}