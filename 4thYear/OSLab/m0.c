#include <unistd.h>
#include <stdio.h>
int main(){
    fork();
    printf("Process id: %d\n",getpid());
    return 0;
}