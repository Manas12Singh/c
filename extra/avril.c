#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <time.h>

#include <unistd.h>

int main()
{
    int *n = (int *)malloc(sizeof(int));
    printf("%x\n", n);
    free(n);
    n = NULL;
    printf("%x\n", n);
    return 0;
}