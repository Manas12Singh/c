#include <stdio.h>

struct item
{
    char name[40];
    int price;
    int quantity;
};

int main()
{
    int n, totalcost = 0;
    char ch;
    printf("Enter the No. of item(N): ");
    scanf("%d%c", &n, &ch);
    struct item item[n];
    printf("Enter the details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item Name: ");
        gets(item[i].name);
        printf("Unit Price(Rs.): ");
        scanf("%d", &item[i].price);
        printf("Quantity (in Nos): ");
        scanf("%d%c", &item[i].quantity);
    }
    for (int i = 0; i < n; i++)
        totalcost += item[i].price * item[i].quantity;
    printf("Total cost of the inventory(Rs.): %d\n", totalcost);
    return 0;
}
