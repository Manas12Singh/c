#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char * longestCommonPrefix(char** , int);

int main()
{
    char *sto[6]={"dog","racecar","car"};
    char **strs = sto;
    char* s=longestCommonPrefix(strs,3);
    printf("%s",s);
    return 0;
}

char* longestCommonPrefix(char** strs, int strsSize)
{
    int l=strlen(strs[0]);
    int c=0;
    for(int i=0;i<l;i++)
    {
        char s2=strs[0][i];
        for(int j=1;j<strsSize;j++)
        {
            if(s2!=strs[j][i])
            {
                c++;
                l=i;
                break;
            }
        }
        if(c!=0) break;
    }
    char *s1;
    s1=(char*)malloc(l*sizeof(char));
    strncpy(s1,strs[0],l);
    return s1;
}