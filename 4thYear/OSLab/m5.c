#include <stdio.h>
#include <unistd.h>
#include <sys/dir.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int func(char fname[]){
    char name[10];
    int age;
    int rollNo;
    char gender;
    scanf("%s",name);
    scanf("%d",&age);
    scanf("%d",&rollNo);
    scanf("%c",&gender);
    int f1=open(fname,O_WRONLY|O_CREAT|O_EXCL,S_IRUSR|S_IWUSR|S_IRGRP|S_IROTH);
    char s[100];
    sprintf(s,"Name: %s\nAge: %d\nRoll No: %d\nGender:%c",name,age,rollNo,gender);
    write(f1,s,strlen(s));
    close(f1);
}

int main()
{
    func("myFile.txt");
    func("friendFile.txt");
    execlp("grep","grep","-f","myFile.txt","friendFile.txt",NULL);
    return 0;
}