#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char name;
    int start;
    int noOfBlocks;
    int *block;
} File;

int main()
{
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);
    File files[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of file %d: ", i + 1);
        scanf("%*c%c", &files[i].name);
        printf("Enter the starting block of file %d: ", i + 1);
        scanf("%d", &files[i].start);
        printf("Enter the number of blocks of file %d: ", i + 1);
        scanf("%d", &files[i].noOfBlocks);
        files[i].block = (int *)malloc(files[i].noOfBlocks * sizeof(int));
        printf("Enter the blocks for file %d: ", i + 1);
        for (int j = 0; j < files[i].noOfBlocks; j++)
            scanf("%d", &files[i].block[j]);
    }
    char search;
    printf("Enter the file to be searched: ");
    scanf("%*c%c", &search);
    int i;
    for (i = 0; i < n; i++)
        if (files[i].name == search)
            break;
    if (i != n)
    {
        printf("File Name\tStart Block\tNo of Blocks\tBlocks occupied\n");
        printf("%c\t\t%d\t\t%d\t\t", files[i].name, files[i].start, files[i].noOfBlocks);
        for (int j = 0; j < files[i].noOfBlocks - 1; j++)
            printf("%d, ", files[i].block[j]);
        printf("%d\n", files[i].block[files[i].noOfBlocks - 1]);
    }
    else
        printf("File not found\n");
    return 0;
}
