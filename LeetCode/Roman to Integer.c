#include<string.h>

int romanToInt(char * s){
    int val=0;
    for(int i=0;i<strlen(s)-1;i++)
    {
        if(s[i]=='I' && (s[i+1]=='V'||s[i+1]=='X'))
            val-=2;
        else if(s[i]=='X' && (s[i+1]=='L'||s[i+1]=='C'))
            val-=20;
        else if(s[i]=='C' && (s[i+1]=='D'||s[i+1]=='M'))
            val-=200;
    }    
    for(int i=0;i<strlen(s);i++)
    {
        switch(s[i])
        {
            case 'I':
                val+=1;
                break;
            case 'V':
                val+=5;
                break;
            case 'X':
                val+=10;
                break;
            case 'L':
                val+=50;
                break;
            case 'C':
                val+=100;
                break;
            case 'D':
                val+=500;
                break;
            case 'M':
                val+=1000;
                break;
        }
    }
    return val;
}