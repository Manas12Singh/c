#include <stdio.h>

int main()
{
    long n;
    float f;
    char s[200];
    scanf("%ld %f %s", &n, &f, s);
    f = f + n;
    sprintf(s, "%s %.2f", s, f);
    printf("%s", s);
    return 0;
}
