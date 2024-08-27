#include <stdio.h>
#include <unistd.h>
#include <sys/dir.h>
#include <stdlib.h>

int main(){
    int p=fork();
    if(p>0){
        wait(NULL);
    }
    else if(p==0){
        printf("Enter the directory: ");
        char dir[100];
        scanf("%s",dir);
        chdir(dir);
        char k[]="ls";
        system(k);
    }
    return 0;
}