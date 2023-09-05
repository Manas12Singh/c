#include <stdio.h>
#include "stackUsingArray.h"

void main()
{
    struct stack s1;
    intialize(&s1, 10);
    push(&s1, 1);
    push(&s1, 2);
    push(&s1, 3);
    print(&s1);
    pop(&s1);
    top(&s1);
    print(&s1);
}