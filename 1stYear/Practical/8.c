#include <stdio.h>
#include <ctype.h>
int main()
{
    FILE *fp = fopen("ThreeParas.txt", "w+");
    char c[1000];
    puts("Enter 3 paras:");
    for (int i = 0; i < 3; i++)
    {
        fgets(c, 1000, stdin);
        fprintf(fp, "%s", c);
    }
    rewind(fp);
    long unsigned vow = 0, cons = 0;
    char ch;
    puts("\nContent of file ThreeParas.txt:\n");
    while (!feof(fp))
    {
        ch = fgetc(fp);
        putchar(ch);
        if (isalpha(ch))
            switch (tolower(ch))
            {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                vow++;
                break;
            default:
                cons++;
            }
    }
    printf("Vowels: %lu\nConsonants: %lu\n", vow, cons);
    fclose(fp);
    return 0;
}