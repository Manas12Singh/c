#include <stdio.h>
#include <string.h>

int main()
{
    int n, j, exist=0, i;
    puts("Enter the total number of names: ");
    scanf("%d", &n);
    n++;
    char s1[n][200], s2[200];
    puts("Enter the names:");
    for (i = 0; i < n; i++)
        gets(s1[i]);
    puts("Search Name:");
    gets(s2);
    for (i = 0; i < n; i++)
    {
        if(strcmp(s1[i],s2)==0)
        {
            exist=1;
            break;
        }
    }
    if (exist == 1)
        printf("%s is found at %d position.", s2, i);
    else
        printf("%s is not found int the list.", s2);
    return 0;
}