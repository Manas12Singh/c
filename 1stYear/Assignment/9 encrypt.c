#include <stdio.h>

int main()
{
    char s1[200];
    int i = 0;
    puts("Original Text:");
    gets(s1);
    while (s1[i] != '\0')
    {
        if (s1[i] > 'A' && s1[i] <= 'Z')
            s1[i]--;
        else if (s1[i] > 'a' && s1[i] <= 'z')
            s1[i]--;
        else if (s1[i] == 'a')
            s1[i] = 'z';
        else if (s1[i] == 'A')
            s1[i] = 'Z';
        i++;
    }
    puts("Ciper Text:");
    puts(s1);
    return 0;
}
