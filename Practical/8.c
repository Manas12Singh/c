#include <stdio.h>
#include <ctype.h>

int main()
{
    FILE *fp = fopen("ThreeParas.txt", "a");
    long unsigned i = 0, n;
    n = ftell(fp);
    fclose(fp);
    long unsigned vow = 0, cons = 0;
    fp = fopen("ThreeParas.txt", "r");
    char ch[n];
    fscanf(fp, "%[^EOF]s", ch);
    puts(ch);
    while (ch[i] != '\0')
    {
        if (isalpha(ch[i]))
        {
            switch (tolower(ch[i]))
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
        i++;
    }
    printf("Vow: %lu\nCons: %lu\n", vow, cons);
    fclose(fp);
    return 0;
}
