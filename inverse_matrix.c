#include <stdio.h>

int rows;
void inverse(int r, int (*)[rows]);

void main()
{
    rows=3;
    printf("No. of rows of matrix: ");
    scanf("%d", &rows); // takes the no. of rows of matrix
    int matrix[rows][rows];
    for (int i = 0; i < rows; i++) // takes row wise elements of matrix like: 12 23 -23
    {
        printf("Enter elements of row %d:\n", i + 1);
        for (int j = 0; j < rows; j++)
            scanf("%d", &matrix[i][j]);
    }
    for (int i = 0; i < rows; i++) // prints the elements of matrix
    {
        for (int j = 0; j < rows; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
    inverse(rows, matrix);
}

void inverse(int r, int (*matrix)[rows])
{
    for (int i = 0; i < r; i++)
    {
        
    }
    
    for (int i = 0; i < r; i++) // prints the elements of matrix
    {
        for (int j = 0; j < r; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}
