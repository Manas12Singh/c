#include <stdio.h>
typedef struct
{
    char Name[20];
    int rollNumber;
    struct
    {
        int day, month, year;
    } dateOfBirth, dateOfAdmission;
} Student;
void main()
{
    Student stud;
    printf("Enter Name: ");
    gets(stud.Name);
    printf("Enter Roll No.: ");
    scanf("%d", &stud.rollNumber);
    printf("Enter Date of Birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &stud.dateOfBirth.day, &stud.dateOfBirth.month, &stud.dateOfBirth.year);
    printf("Enter Date of admission (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &stud.dateOfAdmission.day, &stud.dateOfAdmission.month, &stud.dateOfAdmission.year);
    printf("\nName: %s\n", stud.Name);
    printf("Roll No.: %d\n", stud.rollNumber);
    printf("Date of Birth: %d/%d/%d\n", stud.dateOfBirth.day, stud.dateOfBirth.month, stud.dateOfBirth.year);
    printf("Date of Admission: %d/%d/%d\n", stud.dateOfAdmission.day, stud.dateOfAdmission.month, stud.dateOfAdmission.year);
}
