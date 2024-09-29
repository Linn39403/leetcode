/*
    Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
    The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
    You must write an algorithm that runs in O(n) time and without using the division operation.
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>
//int ans[4] = {0};
int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
    int * ans = malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    //left
    int left = 1;
    for (int i = 0; i < numsSize; i++)
    {
        ans[i] = left;
        left *= nums[i];
    }

    //right
    int right = 1;
    for (int i = numsSize - 1; i > -1; i--)
    {
        ans[i] *= right;
        right *= nums[i];
    }

    return ans;    
}

int test1[4] = {1,2,3,4};
int ans1Size = 0;
int main(void)
{
    productExceptSelf(test1, sizeof(test1)/sizeof(test1[0]), &ans1Size);
    return 0;
}