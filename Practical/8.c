#include <stdio.h>
#include <ctype.h>

long unsigned size(const char *ch)
{
    FILE *fp = fopen(ch, "a");
    long unsigned n = ftell(fp);
    fclose(fp);
    return n;
}

int main()
{
    long unsigned i = 0, n = size("ThreeParas.txt");
    FILE *fp = fopen("ThreeParas.txt", "r");
    long unsigned vow = 0, cons = 0;
    char ch[n];
    
    fscanf(fp, "%[^EOF]", ch);
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
