#include <stdio.h>

struct Run
{
    int (*fun)(int, int);
};

int add(int a, int b)
{
    return a + b;
}

int main()
{
    struct Run a, b;
    a.fun = add;
    b.fun = add;
    printf("%d %x", a.fun(5, 6), (1, 3));
}