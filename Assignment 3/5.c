#include <stdio.h>
#include <string.h>

void main()
{
    char ecode[5], code[5];
    int flag = 0, sal;
    FILE *fp = fopen("Database.txt", "r");
    scanf("%s", ecode);
    while (!feof(fp))
    {
        fscanf(fp, "%s", code);
        if (strcmp(ecode, code) == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        fscanf(fp, " %d", &sal);
        printf("%s %d", ecode, sal);
    }
    else
        printf("Not found");
}
