#include <stdio.h>
#include <ctype.h>

int main(){
    for(int i=0;i<200;i++)
        if(ispunct(i))
            printf("%d:%c\n",i,i);
    return 0;
}