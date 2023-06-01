# include<stdio.h>
#include<stdlib.h>
#include<string.h>


FILE *userdef(FILE *fp,FILE *fp1)
{
  rewind(fp);
  rewind(fp1);
    FILE *fp2 = fopen("merge.txt","w+");
    if(fp2 == NULL)
    {
    printf("file not opening");
    exit(1);
    }
    printf ("Numbers are : \n");
    while((!feof(fp1)) || (!feof(fp)))
    {
        int a;
        if(!feof(fp))
        {
            a = getw(fp);
            putw(a,fp2);
        }
          if(!feof(fp1))
        {
            a = getw(fp1);
            putw(a,fp2);
        }

    }
    rewind(fp2);
return fp2;
}
int main(){
FILE *fp = fopen("odd.txt","w+");
if(fp == NULL)
{
    printf("file not opening");
    exit(1);
}
int i=0;
printf("Enter odd numbers : ");
while(i<5)
{
    int a;
    scanf("%d",&a);
    putw(a,fp);
    i++;
}
FILE *fp1 = fopen("even.txt","w+");
if(fp1 == NULL)
{
    printf("file not opening");
    exit(1);
}
i=0;
printf("Enter even numbers : ");
while(i<5)
{
    int a;
    scanf("%d",&a);
    putw(a,fp1);
    i++;
}
FILE *e=userdef(fp,fp1);
while(!feof(e))
{
    int a=getw(e);
    printf("%d ",e);
}
    return 0;
}