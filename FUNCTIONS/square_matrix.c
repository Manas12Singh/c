#include <stdio.h>

int rows;
void inverse(int r, int (*)[rows]);
void c;

int main()
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

    return 0;
}
