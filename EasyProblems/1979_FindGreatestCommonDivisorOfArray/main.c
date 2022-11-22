#include <stdlib.h>
#include <stdio.h>

/*
    Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
    The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
    
    Constraints:
        2 <= nums.length <= 1000
        1 <= nums[i] <= 1000
*/

void myassert(int iResult, int iExpected,const char * printStr);

int GCD(int x, int y)
{
    int rem = x%y;
    if(rem == 0)
         return y;
    else
        return(GCD(y, rem));
}

int findGCD(int* nums, int numsSize){
    int iMin = INT_MAX, iMax = 0;
    for(int i=0; i < numsSize; i++){
        if(nums[i] > iMax ){
            iMax = nums[i];
        }
        if(nums[i] < iMin){
            iMin = nums[i];
        }
    }
    return GCD(iMin,iMax);    
}




int arr1[]= {2,5,6,9,10};
int arr2[] = {7,5,6,8,3};
int arr3[] = {3,3};
int main(void)
{    
    myassert(findGCD(arr1,sizeof(arr1)/sizeof(int)),2,"Test Case 0"); 
    myassert(findGCD(arr2,sizeof(arr2)/sizeof(int)),1,"Test Case 1"); 
    myassert(findGCD(arr3,sizeof(arr3)/sizeof(int)),3,"Test Case 2"); 
    return 0;
}

void myassert(int iResult, int iExpected,const char * printStr)
{
    if(iResult != iExpected)
    { 
        printf("ERROR: Expected %s, result =  %s, %s\r\n",iExpected, iResult, printStr);
    }
    else
    {
        printf("%s OK\r\n",printStr);
    }
}

