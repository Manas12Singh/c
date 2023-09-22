#include <stdio.h>
#include <ctype.h>

void main()
{
    FILE *fp = fopen("Sample.txt", "r");
    long vow = 0, cons = 0, len = 0;
    char c;
    while ((c = getc(fp)) != EOF)
    {
        if (isalpha(c))
            switch (tolower(c))
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
                break;
            }
        putchar(c);
        len++;
    }
    printf("\nVowels: %d\nConsonants: %d\n", vow, cons);
    printf("Size of file: %d", len);
    fclose(fp);
}
