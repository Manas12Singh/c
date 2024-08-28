#include <stdio.h>

int main()
{
    char ch[500], ch2[11];
    int a[10], i = 0;
    printf("Enter an example of the pattern (max 10 letters): ");
    gets(ch2);
    printf("Enter the text: ");
    gets(ch);
    while (ch2[i] != '\0')
    {
        if (ch2[i] >= 'A' && ch2[i] <= 'Z')
            a[i] += 2;
        else if (ch2[i] >= 'a' && ch2[i] <= 'z')
            a[i] += 1;
    }

    return 0;
}