#include <stdio.h>
#include <string.h>

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
    if (n == 0)
        printf("The sub-string occurs at the end of main string");
    else
        printf("The sub-string does not occurs at the end of main string");
    return 0;
}

int subStrEnd(char S[], char T[])
{
    int l1 = strlen(S), l2 = strlen(T);
    int n = strcmp(S + l1 - l2, T);
    return n;
}
