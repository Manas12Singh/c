#include <stdio.h>

int main()
{
    char s1[200];
    int i = 0;
    puts("Ciper Text:");
    gets(s1);
    while (s1[i] != '\0')
    {
        if (s1[i] >= 'A' && s1[i] < 'Z')
            s1[i]++;
        else if (s1[i] >= 'a' && s1[i] < 'z')
            s1[i]++;
        else if (s1[i] == 'z')
            s1[i] = 'a';
        else if (s1[i] == 'Z')
            s1[i] = 'A';
        i++;
    }
    puts("Decrypted Text:");
    puts(s1);
    return 0;
}
