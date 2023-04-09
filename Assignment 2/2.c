#include <stdio.h>

int main()
{
    int n;
    float f;
    char s[200];
    scanf("%d %f %s", &n, &f, s);
    f += n;
    sprintf(s, "%s %.2f", s, f);
    printf("%s", s);
    return 0;
}
