#include <stdio.h>

typedef struct
{
    char Name[20];
    char EmpCode[5];
    char DOB[20];
    int Salary;
} Employee;

void display(Employee emp)
{
    puts("\n\t\tABC Corporation\n");
    printf("Name\t\t:%s\n", emp.Name);
    printf("EmpCode\t\t:%s\n", emp.EmpCode);
    printf("DOB\t\t:%s\n", emp.DOB);
    printf("Net Salary\t:Rs. %d/-", emp.Salary);
}

int main()
{
    Employee emp;
    printf("Enter the Name: ");
    gets(emp.Name);
    printf("Enter Employee Code: ");
    gets(emp.EmpCode);
    printf("Enter Date of Birth: ");
    gets(emp.DOB);
    printf("Enter Net Salary(in Rs.): ");
    scanf("%d", &emp.Salary);
    display(emp);
    return 0;
}