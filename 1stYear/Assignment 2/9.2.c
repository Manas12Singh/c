#include <stdio.h>
#include <string.h>

int main()
{
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    char name[n][100], temp1[100];
    int sem[n], temp2;
    int per[n], temp3;
    printf("Enter the details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Name: ");
        scanf("%s", &name[i]);
        printf("Semester: ");
        scanf("%d", &sem[i]);
        printf("Marks(%%): ");
        scanf("%d", &per[i]);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (per[i] < per[j])
            {
                strcpy(temp1, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], temp1);

                temp2 = sem[i];
                sem[i] = sem[j];
                sem[j] = temp2;

                temp3 = per[i];
                per[i] = per[j];
                per[j] = temp3;
            }
    printf("Name\t\tSemester No.\tPercentage\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%d\n", name[i], sem[i], per[i]);
    }
    return 0;
}
