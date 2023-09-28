#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *arr;
    int capacity, size, top;
};

void intialize(struct Stack **s1, int cap)
{
    if (*s1)
    {
        printf("Stack already exist.\n");
        return;
    }
    *s1 = (struct Stack *)malloc(sizeof(struct Stack));
    (*s1)->capacity = cap;
    (*s1)->size = 0;
    (*s1)->top = -1;
    (*s1)->arr = (int *)malloc(sizeof(int) * cap);
}

void push(struct Stack *s1, int val)
{
    if (s1->size == s1->capacity)
    {
        printf("Stack already full!\n");
        return;
    }
    s1->top++;
    s1->arr[s1->top] = val;
    s1->size++;
}

void pop(struct Stack *s1)
{
    if (s1->size == 0)
    {
        printf("Stack already empty!\n");
        return;
    }
    printf("Popped value: %d\n", s1->arr[s1->top]);
    s1->top--;
    s1->size--;
}

void top(struct Stack *s1)
{
    if (s1->size == 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    printf("%d\n", s1->arr[s1->top]);
}

void print(struct Stack *s1)
{
    if (s1->size == 0)
    {
        printf("Stack is empty!\n");
        return;
    }
    int n = s1->top;
    printf("Stack: ");
    while (n >= 0)
        printf("%d ", s1->arr[n--]);
    printf("\n");
}

void freeStack(struct Stack **s1)
{
    free((*s1)->arr);
    free(*s1);
    *s1 = NULL;
}

int main()
{
    struct Stack *s1 = NULL;
    while (1)
    {
        int opt, k;
        puts("Options: \n1. Create a new stack. \n2. Push. \n3. Pop. \n4. Top. \n5. Print. \n6. Exit.");
        printf("Enter your choice (1 to 6): ");
        scanf("%d", &opt);
        if (opt == 1)
        {
            int cap;
            printf("Enter the max size of stack: ");
            scanf("%d", &cap);
            intialize(&s1, cap);
        }
        else if (opt >= 2 && opt <= 6)
        {
            if (s1 == NULL)
            {
                printf("Please create a stack first.\n");
                continue;
            }
            switch (opt)
            {
            case 2:
                printf("Enter the value: ");
                scanf("%d", &k);
                push(s1, k);
                break;
            case 3:
                pop(s1);
                break;
            case 4:
                top(s1);
                break;
            case 5:
                print(s1);
                break;
            case 6:
                freeStack(&s1);
                return 0;
            }
        }
        else
            printf("Wrong Choice!");
        printf("\n");
    }
    return 0;
}
