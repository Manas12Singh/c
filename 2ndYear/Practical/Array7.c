#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int *arr;
    int size, cap;
} DynamicArray;

DynamicArray *createDynamicArray()
{
    DynamicArray *temp = (DynamicArray *)malloc(sizeof(DynamicArray));
    temp->cap = 1;
    temp->size = 0;
    temp->arr = (int *)malloc(sizeof(int));
    return temp;
}

void append(DynamicArray *array, int val)
{
    if (array->size == array->cap)
    {
        array->cap *= 2;
        array->arr = (int *)realloc(array->arr, array->cap * sizeof(int));
    }
    array->arr[array->size++] = val;
}

void clear(DynamicArray **array)
{
    free((*array)->arr);
    free(*array);
    *array = NULL;
}

DynamicArray *copy(DynamicArray *Source)
{
    DynamicArray *temp = (DynamicArray *)malloc(sizeof(DynamicArray));
    temp->cap = Source->cap;
    temp->size = Source->size;
    temp->arr = (int *)realloc(Source->arr, sizeof(int) * Source->cap);
    return temp;
}

int count(DynamicArray *array, int val)
{
    int c = 0, i = 0;
    while (i < array->size)
        if (array->arr[i++] == val)
            c++;
    return c;
}

void extend(DynamicArray *array, int *source, int sourceSize)
{
    int f = 0;
    while (array->size + sourceSize > array->cap)
        array->cap *= 2, f = 1;
    if (f == 1)
        array->arr = (int *)realloc(array->arr, array->cap * sizeof(int));
    for (int i = 0; i < sourceSize; i++)
        array->arr[array->size++] = source[i];
}

void printArray(DynamicArray *array)
{
    if (array->size == 0)
    {
        printf("The array is empty.\n");
        return;
    }
    printf("Array: ");
    for (int i = 0; i < array->size; i++)
        printf("%d ", array->arr[i]);
    printf("\n");
}

int indexInArray(DynamicArray *array, int val)
{
    for (int i = 0; i < array->size; i++)
        if (array->arr[i] == val)
            return i;
    return -1;
}

void insert(DynamicArray *array, int index, int val)
{
    if (array->size == array->cap)
    {
        array->cap *= 2;
        array->arr = (int *)realloc(array->arr, array->cap * sizeof(int));
    }
    if (index < 0)
        index = 0;
    else if (index > array->size)
        index = array->size;
    array->size++;
    for (int i = array->size; i > index; i--)
        array->arr[i] = array->arr[i - 1];
    array->arr[index] = val;
}

void pop(DynamicArray *array, int index)
{
    if (index < 0 || index >= array->size)
    {
        printf("Index out of range.\n");
        return;
    }
    array->size--;
    int val = array->arr[index];
    for (int i = index; i < array->size; i++)
        array->arr[i] = array->arr[i + 1];
    if (array->cap / 2.0 == (float)array->size)
    {
        array->cap /= 2;
        array->arr = (int *)realloc(array->arr, sizeof(int) * array->cap);
    }
    printf("Popped value: %d\n", val);
}

int main()
{
    DynamicArray *d1 = createDynamicArray();
    printArray(d1);
    append(d1, 5);
    append(d1, 6);
    printArray(d1);
    int arr[] = {1, 2, 3, 4, 5};
    extend(d1, arr, 5);
    printArray(d1);
    printf("%d\n", count(d1, 5));
    pop(d1, 2);
    printArray(d1);
    clear(&d1);
    return 0;
}