#include<string.h>

int lengthOfLastWord(char * s){
    int c=strlen(s),d=0;
    for(int i=c-1;i>=0;i--)
    {
        if(s[i]!=' ')
            d++;
        else if(d!=0)
            return d;
    }
    return d;
}