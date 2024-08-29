#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

void func(char fname[])
{
    char name[20], section[2], gender;
    int age, rollNo;
    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    printf("Age: ");
    scanf("%d", &age);
    printf("Roll No.: ");
    scanf("%d", &rollNo);
    printf("Gender: ");
    scanf(" %c", &gender);
    printf("Section: ");
    scanf("%s", section);
    int f1 = open(fname, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
    if (f1 < 0)
    {
        perror("Error opening file");
        return;
    }
    char s[100];
    puts(name);
    printf("Name: %s\nAge: %d\nRoll No: %d\nGender:%c\nSection: %s\n", name, age, rollNo, gender, section);
    sprintf(s, "Name: %s\nAge: %d\nRoll No: %d\nGender:%c\nSection: %s", name, age, rollNo, gender, section);
    write(f1, s, strlen(s));
    close(f1);
}

int main()
{
    printf("Your Details:\n");
    func("myFile.txt");
    printf("Friend's Details:\n");
    func("friendFile.txt");
    printf("\nCommon lines:\n");
    execlp("grep", "grep", "-f", "myFile.txt", "friendFile.txt", NULL);
    return 0;
}
