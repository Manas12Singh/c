#include <stdio.h>

char *subString(char s1[], int start, int number);

int main()
{
    int start, number;
    char s1[200];
    puts("Main String:");
    gets(s1);
    puts("Starting Position:");
    scanf("%d", &start);
    puts("Ending Position:");
    scanf("%d", &number);
    char *s2 = subString(s1, start, number);
    puts("Sub-string extracted from the main string: ");
    puts(s2);
    return 0;
}

char *subString(char s1[], int start, int number)
{
    int l = 0, i = 0;
    while (s1[l] != '\0')
        l++;
    while (start + i < l && i < number)
    {
        s1[i] = s1[start + i - 1];
        i++;
    }
    s1[i] = '\0';
    return s1;
}