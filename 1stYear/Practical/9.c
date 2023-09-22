#include <stdio.h>

void main()
{
    FILE *fp1, *fp2;
    fp1 = fopen("Original.txt", "w+");
    char ch[1000], c;
    puts("Enter the text:");
    fgets(ch, 1000, stdin);
    fputs(ch, fp1);
    rewind(fp1);
    fp2 = fopen("Modified.txt", "w+");
    while (!feof(fp1))
    {
        c = fgetc(fp1);
        if (c == ' ')
            continue;
        fputc(c, fp2);
    }
    rewind(fp2);
    fgets(ch, 1000, fp2);
    puts("Content of Modified file:");
    puts(ch);
}
