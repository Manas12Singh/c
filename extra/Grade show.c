#include <stdio.h>

int main()
{
}

int main()
{
    int a;
    printf("Enter the marks: ");
    scanf("%d", &a);
    a /= 10; // or a=a/10;
    switch (a)
    {
    case 10:
    case 9:
        printf("Grade: A");
        break;
    case 8:
        printf("Grade: B");
        break;
    case 7:
        printf("Grade: C");
        break;
    case 6:
        printf("Grade: D");
        break;
    default:
        printf("Grade: F");
        break;
    }
    return 0;
}