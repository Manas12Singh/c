#include <stdio.h>
#include <string.h>

char *subString(char s1[], int start, int number);

int main()
{
    int start, number;
    char s1[200];
    puts("Main String:");
    gets(s1);
    puts("Starting Position:");
    scanf("%d", &start);
    puts("Number of terms:");
    scanf("%d", &number);
    char *s2 = subString(s1, start, number);
    puts("Sub-string extracted from the main string: ");
    puts(s2);
    return 0;
}

char *subString(char s1[], int start, int number)
{
    int l, i = 0;
    l = strlen(s1);
    strncpy(s1, s1 + start - 1, number);
    s1[number] = '\0';
    return s1;
}