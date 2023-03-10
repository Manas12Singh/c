#include <stdio.h>

char *rev(char s1[]);

int main()
{
    int i = 0, flag = 1;
    char s1[200];
    puts("Enter the string: ");
    gets(s1);
    char *s2 = reverse(s1);
    while (s1[i] != '\0')
    {
        if (s1[i] != s2[i])
        {
            flag = 0;
            break;
        }
        i++;
    }
    if (flag == 1)
        puts("Palindrome");
    else
        puts("Not a Palindrome");
    return 0;
}

char *rev(char s1[])
{
    static char s2[100];
    int i = 0, l = 0;
    while (s1[l] != '\0')
        l++;
    while (s1[i] != '\0')
        s2[--l] = s1[i++];
    s2[i] = '\0';
    return s2;
}