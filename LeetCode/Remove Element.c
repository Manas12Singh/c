int removeElement(int* nums, int numsSize, int val){
    int temp;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==val)
        {
            for(int j=i;j<numsSize-1;j++)
            {
                temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
            if(nums[i]==val) i--;
            numsSize--;
        }
    }
    return numsSize;
}