#include <stdio.h>
#include "stackUsingLinkedList.h"

void main()
{
    struct stack *s1 = NULL;
    intialize(&s1);
    push(s1, 1);
    push(s1, 2);
    push(s1, 3);
    print(s1);
    pop(s1);
    pop(s1);
    pop(s1);
    top(s1);
    empty(s1);
    print(s1);
}