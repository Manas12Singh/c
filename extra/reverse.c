#include <stdio.h>

int *reverse(int *p, int n);



// DRY- Don't Repeat Yourself



int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int *p = arr;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        // scanf("%d",p+i);
    }
    int *p1 = reverse(p, n);
    // reverse(arr,n);

    for (int i = 0; i < n; i++)
    {
        // scanf("%d",arr[i]);
        printf("%d %d\n", *(p1 + i), arr[i]);
    }
    return 0;
}



int *reverse(int *p, int n)
{
    static int arr[100];
    int temp;
    for (int i = 0; i < n; i++)
    {
        arr[i] = *(p + n - i - 1);
    }
    return arr;
}

// Create array
//  pass to funtion
//  print result