#include <stdio.h>
#include <string.h>
int compare(char[], char[]);
void main()
{
    char wrd1[20], wrd2[20];
    printf("Enter string 1: ");
    gets(wrd1);
    printf("Enter string 2: ");
    gets(wrd2);
    if (compare(wrd1, wrd2))
        printf("The strings are equal.");
    else
        printf("The strings are not equal.");
}
int compare(char wrd1[], char wrd2[])
{
    int i = 0;
    if (strlen(wrd1) == strlen(wrd2))
    {
        while (wrd1[i] != '\0')
        {
            if (wrd1[i] == wrd2[i])
                return 1;
            else
                return 0;
            i++;
        }
    }
    else
        return 0;
}
