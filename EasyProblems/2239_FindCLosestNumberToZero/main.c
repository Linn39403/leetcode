#include <stdlib.h>
int findClosestNumber(int* nums, int numsSize) {
    int closestNum = nums[0];
    for(int i=1; i<numsSize; i++)
    {
        if(abs(nums[i]) < abs(closestNum))
        {
            closestNum = nums[i];
        }
        else if((abs(nums[i]) == abs(closestNum)) && nums[i] > closestNum)
        {
            closestNum = nums[i];
        }
    }
    return closestNum;
}