#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>

void func(char fname[])
{
    char name[20], section[3], gender;
    int age, rollNo;
    printf("Name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0';
    printf("Age: ");
    scanf("%d", &age);
    printf("Gender: ");
    scanf(" %c", &gender);
    printf("Section: ");
    scanf("%s", section);
    printf("Roll No.: ");
    scanf(" %d%*c", &rollNo);
    int f1 = open(fname, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP);
    if (f1 < 0)
    {
        perror("Error opening file");
        return;
    }
    char s[100];
    sprintf(s, "Name: %s\nAge: %d\nGender: %c\nSection: %s\nRoll No: %d", name, age, gender, section, rollNo);
    write(f1, s, strlen(s));
    close(f1);
    printf("Details written to %s\n", fname);
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
