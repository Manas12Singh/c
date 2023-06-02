#include <stdio.h>
void Operate(FILE *fp1, FILE *fp2)
{
    char ch;
    while (!feof(fp1))
    {
        ch = getc(fp1);
        if (!(ch >= 48 && ch <= 57))
            fputc(ch, fp2);
    }
}
int main()
{
    FILE *fp1, *fp2;
    char str[] = "2 + 2 = 4 but 2 * 2 is also 4.Maths is quite interesting";
    fp1 = fopen("File1.txt", "w+");
    fp2 = fopen("File2.txt", "w+");
    if (fp1 != NULL && fp2 != NULL)
    {
        fprintf(fp1, "%s", str);
        rewind(fp1);
        Operate(fp1, fp2);
        rewind(fp2);
        fgets(str, 100, fp2);
        printf("%s", str);
    }
    fclose(fp1);
    fclose(fp2);
}

/*
Print:  +  =  but  *  is also .Maths is quite interesting
File1: 2 + 2 = 4 but 2 * 2 is also 4.Maths is quite interesting
File2:  +  =  but  *  is also .Maths is quite interesting�
*/