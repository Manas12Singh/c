#include <stdio.h>
#include <stdlib.h>

int is_prime(long n)
{
    if (n < 2)
        return 0;
    for (long i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    FILE *fp = fopen("Numbers.txt", "w+");
    for (int i = 1; i < argc; i++)
        fprintf(fp, "%d ", atoi(argv[i]));
    rewind(fp);
    FILE *prime = fopen("prime.txt", "w+");
    long n;
    while (fscanf(fp, "%ld ", &n) == 1)
    {
        if (is_prime(n))
            fprintf(prime, "%ld ", n);
    }
    rewind(prime);
    while (fscanf(prime, "%ld ", &n) == 1)
        printf("%ld ", n);
    fclose(fp);
    fclose(prime);
    return 0;
}