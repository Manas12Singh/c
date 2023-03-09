#include <stdio.h>
#include <string.h>

int main()
{
    char s1[300];
    int i = 0, j = 0, flag = 1;
    puts("Enter the string:");
    gets(s1);
    while (s1[i] != '\0')
    {
        if (flag)
        {
            if(strncmp("a ",strlwr(s1+i),2)==0)
            {
                i+=2;
                continue;
            }
            else if (strncmp("a\0",strlwr(s1+i),2)==0)
            {
                break;
            }
            else if(strncmp("an ",strlwr(s1+i),3)==0)
            {
                i+=3;
                continue;
            }
            else if(strncmp("an\0",strlwr(s1+i),3)==0)
            {
                break;
            }
            else if(strncmp("the ",strlwr(s1+i),4)==0)
            {
                i+=4;
                continue;
            }
            else if(strncmp("the\0",strlwr(s1+i),4)==0)
            {
                break;
            }
        }
        if (s1[i] == ' ')
            flag = 1;
        else
            flag = 0;
        s1[j] = s1[i];
        i++, j++;
    }
    s1[j] = '\0';
    puts("Formatted string:");
    puts(s1);
    return 0;
}