#include <stdio.h>

void main()
{
    FILE *fp = fopen("Numbers.txt", "r");
    int n;
    fscanf(fp, "%d ", &n);
    printf("%d ", n);
    while (!feof(fp))
    {
        fscanf(fp, "%d ", &n);
        if (n % 9 == 0)
            printf("%d ", n);
    }
    fclose(fp);
}