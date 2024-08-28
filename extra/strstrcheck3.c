#include <stdio.h>
#include <string.h>
int main()
{
    char s1[200], s2[200];
    gets(s1);
    gets(s2);
    if (strstr(s1, s2) != 0)
        printf("Found");
    else
        printf("Not found");
    return 0;
}