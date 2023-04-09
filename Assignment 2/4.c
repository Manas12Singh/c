#include <stdio.h>

int substr(char *p1, char *p2);

int main()
{
    char s1[200], s2[200];
    gets(s1);
    gets(s2);
    char *p1 = s1, *p2 = s2;
    int flag = substr(p1, p2);
    if (flag == 1)
        printf("Sub-string found");
    else
        printf("Sub-string not found");
    return 0;
}

int substr(char *p1, char *p2)
{
    int j;
    while (*p1 != '\0')
    {
        j = 0;
        while (*(p1 + j) == *(p2 + j) && *(p2 + j) != '\0')
            j++;
        if (p2[j] == '\0')
        {
            return 1;
        }
        i++;
    }
    return 0;
}