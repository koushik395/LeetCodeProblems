#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
	int *ret,i,j,pos1,pos2;
	*(returnSize) = 2;
	ret = (int *)malloc(*returnSize * sizeof(int));
	for(i=0;i<numsSize;i++)
	{
		if(i==numsSize-1){
			return NULL;
		}
		for(j=i+1;j<numsSize;j++)
		{
			if((*(nums+i)+ *(nums+j))==target)
			{
				pos1=i;
				pos2=j;
				*(ret + 0) = pos1;
				*(ret + 1) = pos2;
				return ret;
			}
		}
	}
    return NULL;
}


