#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swapRows(float **mat, int row1, int row2, int n)
{
    float* temp = mat[row1];
    mat[row1] = mat[row2];
    mat[row2] = temp;
}

void gaussElimination(float **mat, int n)
{
    for (int i = 0; i < n; i++)
    {
        int maxRow = i;
        for (int k = i + 1; k < n; k++)
            if (abs(mat[k][i]) > abs(mat[maxRow][i]))
                maxRow = k;
        if (maxRow != i)
            swapRows(mat, i, maxRow, n);
        for (int k = i + 1; k < n; k++)
        {
            float factor = mat[k][i] / mat[i][i];
            for (int j = i; j <= n; j++)
                mat[k][j] -= factor * mat[i][j];
        }
    }
}

void backSubstitution(float **mat, float *x, int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        x[i] = mat[i][n] / mat[i][i];
        for (int j = i - 1; j >= 0; j--)
            mat[j][n] -= mat[j][i] * x[i];
    }
}

int main()
{
    int n;
    float **mat;
    float *x;

    printf("Enter the number of unknowns: ");
    scanf("%d", &n);

    mat = (float **)malloc(n * sizeof(float *));
    for (int i = 0; i < n; i++)
        mat[i] = (float *)malloc((n + 1) * sizeof(float));
    x = (float *)malloc(n * sizeof(float));

    printf("Enter the augmented matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%f", &mat[i][j]);

    gaussElimination(mat, n);

    backSubstitution(mat, x, n);

    printf("Solution:\n");
    for (int i = 0; i < n; i++)
        printf("x%d = %f\n", i + 1, x[i]);

    for (int i = 0; i < n; i++)
        free(mat[i]);
    free(mat);
    free(x);

    return 0;
}
