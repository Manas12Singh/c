#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product
{
    char product_Id;
    char product_Name[30];
    int total_sale;
    char product_Grade;
    struct Product *next;
} Product;

typedef struct
{
    struct Product *front;
} ProductQueue;

ProductQueue *createQueue()
{
    ProductQueue *temp = (ProductQueue *)malloc(sizeof(ProductQueue));
    temp->front = NULL;
    return temp;
}

void enqueue(ProductQueue *q)
{
    Product *temp = (Product *)malloc(sizeof(Product));
    if (!temp)
    {
        printf("Memory full!\n");
        return;
    }
    printf("Enter Product ID: ");
    scanf("%c%*c", &(temp->product_Id));
    printf("Enter Product Name: ");
    gets_s(temp->product_Name, 30);
    printf("Enter Total Sale: ");
    scanf("%d%*c", &(temp->total_sale));
    printf("Enter Product Grade: ");
    scanf("%c", &(temp->product_Grade));
    temp->next = NULL;
    if (q->front == NULL)
        q->front = temp;
    else
    {
        Product *trav = q->front;
        while (trav->next != NULL)
            trav = trav->next;
        trav->next = temp;
    }
}

void front(ProductQueue *q)
{
    if (q->front == NULL)
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Product ID: %c\n", q->front->product_Id);
    printf("Product Name: %s\n", q->front->product_Name);
    printf("Total Sale: %d\n", q->front->total_sale);
    printf("Product Grade: %c\n", q->front->product_Grade);
}

void dequeue(ProductQueue *q)
{
    if (q->front == NULL)
    {
        printf("Queue already empty!\n");
        return;
    }
    struct Product *temp = q->front;
    q->front = q->front->next;
    free(temp);
}

void destroyQueue(ProductQueue **q)
{
    if (*q == NULL)
        return;
    while ((*q)->front != NULL)
    {
        Product *temp = (*q)->front;
        (*q)->front = (*q)->front->next;
        free(temp);
    }
    free(*q);
    *q = NULL;
}

int main()
{
    int opt;
    ProductQueue *q1 = createQueue();
    while (1)
    {
        printf("Options:\n1. Enque.\n2. Deque.\n3. Front.\n4. Exit.\n");
        printf("Enter your choice (1 to 4): ");
        scanf("%d%*c", &opt);
        switch (opt)
        {
        case 1:
            enqueue(q1);
            break;
        case 2:
            dequeue(q1);
            break;
        case 3:
            front(q1);
            break;
        case 4:
            destroyQueue(&q1);
            return 0;
        default:
            printf("Wrong Choice!\n");
        }
    }
    return 0;
}