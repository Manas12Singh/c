#include <stdio.h>
#include <unistd.h>
#include <sys/dir.h>

int main(){
    DIR* d=opendir(".");
    struct dirent *d1;
    while(d1=readdir(d))
        printf("%s\n",d1->d_name);
    closedir(d);
    return 0;
}