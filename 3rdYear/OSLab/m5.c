#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

int func(char fname[])
{
    char name[10];
    int age;
    int rollNo;
    char gender;
    scanf("%s %d %d %c%*c", &name, &age, &rollNo, &gender);
    int f1 = open(fname, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP);
    char s[100];
    printf("Name: %s\nAge: %d\nRoll No: %d\nGender:%c\n", name, age, rollNo, gender);
    sprintf(s, "Name: %s\nAge: %d\nRoll No: %d\nGender:%c", name, age, rollNo, gender);
    write(f1, s, strlen(s));
    close(f1);
}

int main()
{
    func("myFile.txt");
    func("friendFile.txt");
    execlp("grep", "grep", "-f", "myFile.txt", "friendFile.txt", NULL);
    return 0;
}
