#include <stdio.h>

FILE *merge_files(FILE *even, FILE *odd)
{
    FILE *merge = fopen("Merge.txt", "w+");
    int flag = 1;
    long n;
    while (!feof(even) || !feof(odd))
    {
        if (flag == 1)
        {
            fscanf(odd, "%ld ", &n);
            if (!feof(even))
                flag = 0;
        }
        else
        {
            fscanf(even, "%ld ", &n);
            if (!feof(odd))
                flag = 1;
        }
        fprintf(merge, "%ld ", n);
    }
    rewind(merge);
    return merge;
}

void main()
{
    FILE *even, *odd, *merge;
    long n;
    even = fopen("Even.txt", "r");
    odd = fopen("Odd.txt", "r");
    merge = merge_files(even, odd);
    while (fscanf(merge, "%ld ", &n) == 1)
    {
        printf("%ld ", n);
    }
    fclose(even);
    fclose(odd);
    fclose(merge);
}
