#include <stdio.h>

void main()
{
    FILE *fp = fopen("Data.bin", "rb");
    char ch1[110] = "", ch2[20] = "";
    fseek(fp, -100, SEEK_END);
    fread(ch1, sizeof(char), 100, fp);
    rewind(fp);
    fread(ch2, sizeof(char), 10, fp);
    fclose(fp);
    printf("%s %s", ch1, ch2);
}