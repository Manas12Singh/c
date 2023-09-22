#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char s[] = "GOOD MORNING";
    printf("\n %20.10s", s);
    printf("\n %s", s[0]);
    printf("\n %s", &s[5]);
    return 0;
}
