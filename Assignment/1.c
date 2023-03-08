#include <stdio.h>

char *reverse(char s1[]);

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

char *reverse(char s1[])
{
    static char s2[200];
    int l = 0, i = 0;
    while (s1[l] != '\0')
        l++;
    l--;
    while (l >= 0)
    {
        s2[i] = s1[l];
        i++;
        l--;
    }
    s2[i] = '\0';
    return s2;
}