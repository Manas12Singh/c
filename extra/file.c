#include <stdio.h>

void main()
{
    char c;
    int check = 1, i = 1;
    FILE *fp = fopen("text.txt", "r");
    while (!feof(fp))
    {
        if (check == 1)
        {
            printf("%d. ", i++);
            check = 0;
        }
        else
        {
            c = fgetc(fp);
            putchar(c);
            if (c == '\n')
                check = 1;
        }
    }
}
