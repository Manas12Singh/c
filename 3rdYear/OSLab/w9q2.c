#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BLOCKS 100

typedef struct DiskBlock
{
    int blockNo;
    struct DiskBlock *next;
} DiskBlock;

typedef struct
{
    char name;
    int start;
    int noOfBlocks;
    DiskBlock *block;
} File;

int isBlockAssigned(int block, int assignedBlocks[])
{
    return assignedBlocks[block];
}

int getRandomBlock(int assignedBlocks[])
{
    int block;
    do
    {
        block = rand() % MAX_BLOCKS;
    } while (isBlockAssigned(block, assignedBlocks));
    assignedBlocks[block] = 1;
    return block;
}

int main()
{
    srand(time(0));
    int assignedBlocks[MAX_BLOCKS] = {0};
    int n;
    printf("Enter the number of files: ");
    scanf("%d", &n);
    File files[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the name of file %d: ", i + 1);
        scanf("%*c%c", &files[i].name);
        printf("Enter the starting block of file %d: ", i + 1);
        files[i].start = getRandomBlock(assignedBlocks);
        printf("Enter the number of blocks of file %d: ", i + 1);
        scanf("%d", &files[i].noOfBlocks);
        files[i].block = (DiskBlock *)malloc(sizeof(DiskBlock));
        files[i].block->blockNo = files[i].start;
        assignedBlocks[files[i].start] = 1;
        DiskBlock *temp = files[i].block;
        for (int j = 1; j < files[i].noOfBlocks; j++)
        {
            temp->next = (DiskBlock *)malloc(sizeof(DiskBlock));
            temp = temp->next;
            temp->blockNo = getRandomBlock(assignedBlocks);
        }
        temp->next = NULL;
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
        DiskBlock *temp = files[i].block;
        for (int j = 0; j < files[i].noOfBlocks - 1; j++)
        {
            printf("%d, ", temp->blockNo);
            temp = temp->next;
        }
        printf("%d\n", temp->blockNo);
    }
    else
        printf("File not found\n");
    return 0;
}