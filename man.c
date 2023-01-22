#include <stdio.h>
void transpose()
{
    int i, j;
    int matrix[2][3], transpose_matrix[3][2];
    printf("Enter the 2x3 matrix: \n");
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            transpose_matrix[j][i] = matrix[i][j];
        }
    }
    printf("Transpose matrix is: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", transpose_matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    return 0;
}