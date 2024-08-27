#include <unistd.h>
#include <stdio.h>
int main(){
    int p=fork();
    printf("Process id: %d\n",p);
    return 0;
}