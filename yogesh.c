#include <stdio.h>

typedef struct
{
    char name[20];
    int rollNo;
    int marks[3];
} student;

int main()
{
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    student s[n], max;
    float p, percent = 0;
    for (int i = 0; i < n; i++)
    {
        fflush(stdin);
        printf("Enter the name: ");
        scanf("%[^\n]s", s[i].name);
        printf("Enter the roll no: ");
        scanf("%d", &s[i].rollNo);
        for (int j = 0; j < 3; j++)
        {
            printf("Enter the marks of subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        p = 0;
        for (int j = 0; j < 3; j++)
            p += s[i].marks[j];
        p /= 3;
        if (p > percent)
        {
            max = s[i];
            percent = p;
        }
    }
    puts("Student with highest percentage:");
    printf("Name: %s\n", max.name);
    printf("Roll No: %d\n", max.rollNo);
    for (int j = 0; j < 3; j++)
        printf("Marks in subject %d: %d\n", j, max.marks[j]);
    return 0;
}