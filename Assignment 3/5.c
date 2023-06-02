#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    char ecode[5], data[100];
    long sal = -1;
    FILE *fp = fopen("Database.txt", "r");
    scanf("%s", ecode);
    while (!feof(fp))
    {
        fgets(data, 100, fp);
        if (strncmp(ecode, data, 4) == 0)
        {
            sal = atoi(strrchr(data, ' ') + 1);
            break;
        }
    }
    if (sal != -1)
        printf("Salary: %ld", sal);
    else
        printf("Not Found");
}

/*
Alternate:
#include <stdio.h>
#include <string.h>

void main()
{
    char ecode[5], data[100];
    char *sal = NULL;
    FILE *fp = fopen("Database.txt", "r");
    scanf("%s", ecode);
    while (!feof(fp))
    {
        fgets(data, 100, fp);
        if (strncmp(ecode, data, 4) == 0)
        {
            sal = strrchr(data, ' ') + 1;
            break;
        }
    }
    if (sal != NULL)
        printf("Salary: %s", sal);
    else
        printf("Not Found");
}
*/
