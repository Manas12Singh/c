#include <stdio.h>
void Fun(FILE *fp)
{
    char str[] = {"Somewher in the middle I remember that I had completely forgotten to lock the door"};
    fputs(str, fp);
}
int main()
{
    FILE *fp = fopen("File123.txt", "w+");
    if (fp != NULL)
    {
        Fun(fp);
        printf("Size of the file is: %d", ftell(fp));
    }
    fclose(fp);
}

/*
Prints: Size of the file 82.
Add data to the file
*/