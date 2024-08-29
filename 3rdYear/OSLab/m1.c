#include <unistd.h>
#include <stdio.h>
int main(){
    int p=fork();
    if(p>0){
        printf("Process id: %d\n",getpid());
        printf("Process id of child: %d\n",p);
    }
    else if(p==0){
        printf("Process id: %d\n",getpid());
        printf("Process id of parent: %d\n",getppid());
    }
    printf("\n");
    return 0;
}