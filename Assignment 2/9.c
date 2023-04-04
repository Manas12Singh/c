#include <stdio.h>

struct student
{
    char name[40];
    int sem;
    int marks;
};

int main()
{
    int n;
    printf("Enter the value of N: ");
    scanf("%d", &n);
    struct student student[n], temp;
    printf("Enter the details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Name: ");
        scanf("%s", &student[i].name);
        printf("Semester: ");
        scanf("%d", &student[i].sem);
        printf("Marks(%%): ");
        scanf("%d", &student[i].marks);
    }
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (student[i].marks < student[j].marks)
            {
                temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
    printf("Name\t\tSemester No.\tPercentage\n");
    for (int i = 0; i < n; i++)
    {
        printf("%s\t\t%d\t\t%d\n", student[i].name, student[i].sem, student[i].marks);
    }
    return 0;
}
