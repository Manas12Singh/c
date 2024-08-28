#include <stdio.h>

int main()
{
    int n, totalcost = 0;
    char ch;
    printf("Enter the No. of item(N): ");
    scanf("%d%c", &n, &ch);
    char name[n][100];
    int price[n], quantity[n];
    printf("Enter the details:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Item Name: ");
        gets(name[i]);
        printf("Unit Price(Rs.): ");
        scanf("%d", &price[i]);
        printf("Quantity (in Nos): ");
        scanf("%d%c", &quantity[i], &ch);
    }
    for (int i = 0; i < n; i++)
        totalcost += price[i] * quantity[i];
    printf("Total cost of the inventory(Rs.): %d\n", totalcost);
    return 0;
}
