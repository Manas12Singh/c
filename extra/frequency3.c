#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char wrd[50];
    int a[26], c = 0;
    memset(a, 0, sizeof(a));
    gets(wrd);
    for (int i = 0; i < strlen(wrd); i++)
    {
        int x = wrd[i] - 'a';
        if (x >= 0 && x < 26)
            ++a[x];
    }
    for (int i = 0; i < 26; i++)
    {
        if (a[i] != 0)
        {
            char g = i + 97;
            printf("%c: %d\n", g, a[i]);
        }
    }
    return 0;
}
