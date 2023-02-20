#include<stdio.h>
#include<stdlib.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int j,i;
    int *arr;
    arr=(int *)malloc(8);
    *returnSize=2;
    for(i=0;i<numsSize-1;i++)
    {
        for(j=i+1;j<numsSize;j++)
        {
            if(nums[i]+nums[j]==target)
            {
                *arr=i;
                *(arr+1)=j;
                break; 
            }
        }
    }
    return arr;
}