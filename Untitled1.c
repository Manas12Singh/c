#include<stdio.h>



int main() {
    char ch,s[25],sen[100];
    scanf("%c",&ch);
    printf("%c\n",ch);
//    scanf("%s",s);
//    printf("%s\n",s);
    //scanf("%s",sen);
    scanf("\n%[^\n]s",sen);
    printf("%s\n",sen);
}
