#include <stdio.h>
#include <stdlib.h>

struct student
{
    int data;
    struct student *link;
};

int main()
{
    int n;
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    struct student *start = calloc(1, sizeof(struct student));
    scanf("%d", &(start->data));
    struct student *current = start;
    for (int i = 1; i < n; i++)
    {
        current->link = (struct student *)calloc(1, sizeof(struct student));
        current = current->link;
        scanf("%d", &(current->data));
    }
    current = start;
    int c = 0;
    while (current != NULL)
    {
        c++;
        current = current->link;
    }
    printf("%d", c);
    return 0;
}
