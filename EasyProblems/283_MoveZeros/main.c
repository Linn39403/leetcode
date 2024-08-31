#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
   Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
    Note that you must do this in-place without making a copy of the array.
*/
#define SWAP(A, B) { int temp = A; A = B; B = temp; }
void moveZeroes(int* nums, int numsSize) 
{
    if (numsSize == 0 || numsSize == 1) return;

    int lastNonZeroIndex = 0;

    // Move all non-zero elements to the beginning of the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            SWAP(nums[lastNonZeroIndex], nums[i]);
            lastNonZeroIndex++;
        }
    }

    // The remaining elements after lastNonZeroIndex will naturally be zeros
}


int nums1[5] = {0,1,0,3,12};

int main(void)
{     
    moveZeroes(nums1,sizeof(nums1)/sizeof(nums1[0]));
    return 0;
}

void myassert(bool bResult, bool bExpected, char * cPtrTestName)
{
    if(bResult != bExpected)
    {
        printf("%s. ERROR: Expected %d, result =  %d\r\n",cPtrTestName, bExpected, bResult);
    }
    else
    {
        printf("%s. OK: Expected %d, result =  %d\r\n",cPtrTestName, bExpected, bResult);
    }
}

