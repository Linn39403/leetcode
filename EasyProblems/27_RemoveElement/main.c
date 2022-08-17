#include "string.h"
#include "stdio.h"
void myassert(int result, int expected, char * printStr);

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int * arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
  
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] < arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

int removeElement(int* nums, int numsSize, int val)
{
    int numOfValElements = numsSize;
    if( numsSize == 0 ) return 0;    

    //remove val and put -1
    for(int i = 0 ; i < numsSize ; i++)
    {
        if(val == nums[i])
        {
            nums[i] = -1;
            numOfValElements--;
        }
    }

    bubbleSort(nums, numsSize); 
    return numOfValElements;
}

int test1[] = {3,2,2,3};
int test2[] = {0,1,2,2,3,0,4,2,1,2,2,2,2,2};
int test3[1] = {1};
int test4[] = {2,2,3};
int main(void)
{
    myassert(removeElement(test1, sizeof(test1)/sizeof(int), 3),
    2,
    "Test1, The return should be 2");
    myassert(removeElement(test2, sizeof(test2)/sizeof(int), 2)
    ,6,
    "Test2, The return should be 6");
    myassert(removeElement(test3, sizeof(test3)/sizeof(int), 1)
    ,0,
    "Test3, The return should be 0");    
    myassert(removeElement(test4, sizeof(test4)/sizeof(int), 2)
    ,1,
    "Test4, The return should be 1");  
    return 0;
}


void myassert(int result, int expected, char * printStr)
{
    if(expected != result)
    {
        printf("ERROR: Expected %d, result =  %d, %s\r\n",expected, result, printStr);
    }
    else
    {
        printf("OK: Expected %d, result =  %d, %s\r\n",expected, result, printStr);
    }
}

