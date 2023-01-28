bool isPalindrome(int x){
    if(x==0)
        return true;
    else if(x<0 || x%10==0)
        return false;
    else
    {
        int p=-1,t=x,i;
        while(t!=0)
        {
            t/=10;
            p++;
        }
        for(i=0;i<p;i+=2)
        {
            printf("%d ",x);
            if(x/(int)pow(10,p-i)!=x%10)
                return false;
            x/=10;
            x%=(int)pow(10,p-i-1);
        }
        return true;
    }
}