#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
/*
    Reverse bits of a given 32 bits unsigned integer.
*/
void myassert(uint32_t iResult, uint32_t iExpected, char * cPtrTestName);
int missingNumber(int* nums, int numsSize) {
    int A = 0, B = 0;
    for(int i = 0 ; i < numsSize; i++)
    {
        A ^= nums[i];
    }
    for(int i = 0; i < numsSize+1; i++)
    {
        B ^= i;
    }
    return A^B;
}

int main(void)
{
    int nums_1[] = {3,0,1};
    int nums_2[] = {0,1};
    int nums_3[] = {9,6,4,2,3,5,7,0,1};
    myassert(missingNumber(nums_1,sizeof(nums_1)/sizeof(nums_1[0])),2,"Test case 1");
    myassert(missingNumber(nums_2,sizeof(nums_2)/sizeof(nums_2[0])),2,"Test case 2");
    myassert(missingNumber(nums_3,sizeof(nums_3)/sizeof(nums_3[0])),8,"Test case 3");
    return 0;
}

void myassert(uint32_t iResult, uint32_t iExpected, char * cPtrTestName)
{
    if(iResult != iExpected)
    {
        printf("%s. ERROR: Expected %u, result =  %u\r\n",cPtrTestName, iExpected, iResult);
    }
    else
    {
        printf("%s. OK: Expected %u, result =  %u\r\n",cPtrTestName, iExpected, iResult);
    }
}



