#include <stdio.h>

int subStrEnd(char S[], char T[]);

int main()
{
    int n;
    char S[200], T[200];
    puts("Enter the main string:");
    gets(S);
    puts("Enter the sub-string:");
    gets(T);
    n = subStrEnd(S, T);
    if (n)
        printf("The sub-string occurs at the end of main string");
    else
        printf("The sub-string does not occurs at the end of main string");
    return 0;
}

int subStrEnd(char S[], char T[])
{
    int l1 = 0, l2 = 0;
    while (S[l1] != '\0')
        l1++;
    while (T[l2] != '\0')
        l2++;
    if (l1 < l2)
        return 0;
    while (l2 >= 0)
    {
        if (S[l1] != T[l2])
            return 0;
        l1--, l2--;
    }
    return 1;
}