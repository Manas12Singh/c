#include <stdio.h>

struct node
{
    int n;
    struct node *link;
};

int main()
{
    struct node *start = NULL, *p;
    int n, data;
    scanf("%d", &n);
    if (n == 0)
        return 0;
    scanf("%d", &data);
    start->n = data;
    for (int i = 1; i < n; i++)
    {
        scanf("%d", &data);
        
        p=start;
        while(p->link!=NULL)
            p=p->link;
        p->link
    }
    return 0;
}
