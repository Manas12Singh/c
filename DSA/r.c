#include <stdio.h>
#include <conio.h>

int main()
{
    char *c;
    FILE *fp;
    fp = fopen("man.txt", "r+");
    char *k = fgets(c, 100, fp);
    puts(c);
    int f = fputs("Lello", fp);
    printf("%d", f);
    fclose(fp);
    return 0;
}
