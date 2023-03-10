#include <stdio.h>

int firstBlankSpace(char s1[]);

int main()
{
    int position;
    char s1[200];
    puts("Enter the String:");
    gets(s1);
    position = firstBlankSpace(s1);
    if (position > 0)
        printf("First blank space occurs at %d", position);
    else
        puts("Blank Space not found");
    return 0;
}

int firstBlankSpace(char s1[])
{
    int i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] == ' ')
            return i + 1;
        i++;
    }
    return -1;
}
