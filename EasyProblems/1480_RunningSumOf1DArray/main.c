#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void myassert(int * iPtrResult, int * iPtrExpected, int iPtrSize, char * cPtrStr);

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    int * iPtr = calloc(numsSize, sizeof(int));
    iPtr[0] = nums[0]; //copy first index 0
    if(numsSize == 1) return iPtr;
    memcpy(&iPtr[1],&nums[1],(numsSize-1)*sizeof(int));

    //for(int i = 1 ; i < numsSize ; i ++)
    for(int i = numsSize ; i > 0 ; i --)
    {
        iPtr[numsSize-i+1] += ( iPtr[numsSize-i] );
    }
    * returnSize = numsSize;
    return iPtr;
}

int nums1[] = {1,2,3,4};
int nums2[] = {1,1,1,1};
int nums3[] = {3,1,2,10,1};
int iReturnSize = 0;
int * iPtrAnswer;
int main(void)
{
    iPtrAnswer = runningSum(nums1, sizeof(nums1)/sizeof(int), &iReturnSize);
    myassert(iPtrAnswer, (int[]){1,3,6,10}, sizeof(nums1), "num1");
    free(iPtrAnswer);
    
    iPtrAnswer = runningSum(nums2, sizeof(nums2)/sizeof(int), &iReturnSize);
    myassert(iPtrAnswer, (int[]){1,2,3,4,5}, sizeof(nums2), "num2");
    free(iPtrAnswer);
    
    iPtrAnswer = runningSum(nums3, sizeof(nums3)/sizeof(int), &iReturnSize);
    myassert(iPtrAnswer, (int[]){3,4,6,16,17}, sizeof(nums3), "num3");
    free(iPtrAnswer);
    return 0;
}


void myassert(int * iPtrResult, int * iPtrExpected, int iPtrSize, char * cPtrStr)
{
    if(memcmp(iPtrResult,iPtrExpected,iPtrSize) == 0)
    {
        printf("%s OK, Result = { %d",cPtrStr, iPtrResult[0]);
        if(iPtrSize / 4 > 1)
        {
            for(int i = 1 ; i < iPtrSize / 4; i ++)
            {
                printf(", %d", iPtrResult[i]);
            }    
        }
        printf("}\r\n");
    }
    else
    {
        printf("%s ERROR, Result = { %d",cPtrStr, iPtrResult[0]);
        if(iPtrSize > 1)
        {
            for(int i = 1 ; i < iPtrSize / 4; i ++)
            {
                printf(", %d", iPtrResult[i]);
            }    
        }
        printf("}, Expected = { %d", iPtrExpected[0]);
        if(iPtrSize > 1)
        {
            for(int i = 1 ; i < iPtrSize / 4; i ++)
            {
                printf(", %d", iPtrExpected[i]);
            }    
        } 
        printf("}\r\n");     
    }
}