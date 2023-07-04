#include <stdio.h>

int main()
{
    FILE *fp=fopen("abc.txt","w+");
    int a,p,i=0;
while (i<5)
{
    scanf("%d",&a);
    fprintf(fp,"%d ",a);
    i++;
}
rewind(fp);                     //Add this
while (fscanf(fp,"%d ",&p)==1)  // It's "%d ", not "%d"
{
    printf("%d",p);
}


    return 0;
}

