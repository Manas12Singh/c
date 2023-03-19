#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool s(char *sen, char *search)
{
    int k = 1, i = 0;
    while (*sen != '\0')
    {
        if (k == 1 || *(sen - 1) == ' ')
        {
            if (*sen == search[i])
            {
                i++;
                if (i == strlen(search) && (*(sen + 1) == ' ' || *(sen + 1) == '\0'))
                    return true;
            }
            else
                i = 0;
        }
        k = 0;
        sen++;
    }
    return false;
}
void main()
{
    char sen[100], search[20];
    gets(sen);
    gets(search);
    if (s(sen, search))
        printf("Found");
    else
        printf("Not found");
}