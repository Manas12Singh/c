#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct node
{
    char id;
    char name[50];
    int total_scale;
    char grade;
    struct node *next;
};
struct node *enqueue(struct node *front, struct node **rear)
{
    char id, grade;
    char name[50];
    int total_scale;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter id\n");
    scanf(" %c", &id);
    printf("Enter name\n");
    scanf("%s", name);
    printf("Enter grade\n");
    scanf(" %c", &grade);
    printf("Enter total_scale\n");
    scanf("%d", &total_scale);
    newnode->grade = grade;
    newnode->id = id;
    strcpy(newnode->name, name);
    newnode->total_scale = total_scale;
    newnode->next = NULL;
    if (front == NULL && *rear == NULL)
    {
        front = *rear = newnode;
    }
    else
    {
        (*rear)->next = newnode;
        *rear = newnode;
    }
    return *rear;
}
void dequeue(struct node **front)
{
    struct node *temp = *front;
    *front = (*front)->next;
    free(temp);
}
void display(struct node *front)
{
    struct node *temp = front;
    while (temp != NULL)
    {
        printf("%c %s %d %c ", temp->id, temp->name, temp->total_scale, temp->grade);
        temp = temp->next;
    }
}
int main()
{
    struct node *front = NULL;
    struct node *rear = NULL;
    rear = enqueue(front, &rear);
    rear = enqueue(front, &rear);
    printf("\n");
    dequeue(&front);
    printf("\n");
    display(front);
    return 0;
}