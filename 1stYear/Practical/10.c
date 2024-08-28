#include <stdio.h>
#include <stdlib.h>
void main(int argc, char *argv[])
{
    FILE *number = fopen("Number.txt", "w+");
    long n;
    for (int i = 1; i < argc; i++)
    {
        n = atoi(argv[i]);
        fprintf(number, "%ld ", n);
    }
    rewind(number);
    FILE *odd = fopen("odd.txt", "w");
    FILE *even = fopen("even.txt", "w");
    while (!feof(number))
    {
        fscanf(number, "%ld ", &n);
        if (n % 2 == 0)
            fprintf(even, "%ld ", n);
        else
            fprintf(odd, "%ld ", n);
    }
    fclose(number);
    fclose(even);
    fclose(odd);
}
