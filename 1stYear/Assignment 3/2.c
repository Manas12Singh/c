#include <stdio.h>

FILE *merge_files(FILE *even, FILE *odd)
{
    FILE *merge = fopen("Merge.txt", "w+");
    int flag = 1;
    long n;
    while (!feof(even) || !feof(odd))
    {
        if (!feof(odd))
        {
            fscanf(odd, "%ld ", &n);
            fprintf(merge, "%ld ", n);
        }
        if (!feof(even))
        {
            fscanf(even, "%ld ", &n);
            fprintf(merge, "%ld ", n);
        }
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
