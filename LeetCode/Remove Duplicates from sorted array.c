int removeDuplicates(int* nums, int numsSize){
    int i,j=1;
    int a=nums[0];
    for(i=1;i<numsSize;i++)
    {
        if(nums[i]!=a)
        {
            a=nums[j]=nums[i];
            j++;
        }
    }
    return j;
}