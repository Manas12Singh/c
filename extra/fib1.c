#include <stdio.h>

typedef struct man
{
    char ch;
    int n;
} men;

void def(men *m)
{
    men *m1 = {'a', 23};
    m = m1;
}

void main()
{
    men m1, m2;
    def(&m1);
    printf("%c %d", m1.ch, m1.n);
}
