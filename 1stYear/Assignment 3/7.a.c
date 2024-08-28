#include <stdio.h>
int main()
{
    FILE *fp = fopen("File123.txt", "r");
    if (fp != NULL)
    {
        fprintf(fp, "Stitch in time saves nine");
    }
    fclose(fp);
}

//Does nothing