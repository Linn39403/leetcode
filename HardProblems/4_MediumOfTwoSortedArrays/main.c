#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
* Given two sorted arrays nums1 and nums2 of size m and n respectively, 
* return the median of the two sorted arrays.
* The overall run time complexity should be O(log (m+n)).
*/

void myassert(double dResult, double dExpected, char * cPtrTestName);
double getMedium(int * iArray, int iSize)
{
    double dAns;
    if(iSize%2 == 0)
    {
        dAns = (double)(iArray[iSize/2] + iArray[(iSize/2)-1])/2;
    }
    else
    {
        dAns = iArray[iSize/2];
    }
    return dAns;        
}
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
    double dAns = 0;
    double dNums1Mean = 0, dNums2Mean = 0;
    int iTotalSize = (nums1Size+nums2Size);
    int iIdx1 = 0, iIdx2 = 0;
    int iMergedArray[2000] = {0};
    //copy into merged arr
    if(nums1Size != 0 && nums2Size != 0)
    {
        int i = 0 , j = 0, k = 0;
        while (i < nums1Size && j < nums2Size)  
        {
            if (nums1[i] < nums2[j])
                iMergedArray[k++] = nums1[i++];   
            else
                iMergedArray[k++] = nums2[j++];
        }
    
        while (i < nums1Size)    //copying the leftover elements of a, if any
            iMergedArray[k++] = nums1[i++];
    
        while (j < nums2Size)    //copying the leftover elements of b, if any
            iMergedArray[k++] = nums2[j++];        
        dAns = getMedium(iMergedArray, iTotalSize);     
    }
    else
    {
        if(nums1Size==0)
        {
            dAns = getMedium(nums2,nums2Size);
        }
        else
        {
            dAns = getMedium(nums1,nums1Size);
        }
    }
    return (dAns);   
}

int iNumsA1[2] = {1,2};
int iNumsA2[1] = {3};
int iNumsB1[2] = {1,2};
int iNumsB2[2] = {3,4};
int iNumsC1[2] = {1,3};
int iNumsC2[2] = {2,7};
int main(void)
{
    myassert(findMedianSortedArrays(iNumsA1,sizeof(iNumsA1)/sizeof(int),iNumsA2,sizeof(iNumsA2)/sizeof(int)),
             2.0, "Test Case 1");
    myassert(findMedianSortedArrays(iNumsB1,sizeof(iNumsB1)/sizeof(int),iNumsB2,sizeof(iNumsB2)/sizeof(int)),
             2.5, "Test Case 2");             
    myassert(findMedianSortedArrays(iNumsC1,sizeof(iNumsC1)/sizeof(int),iNumsC2,sizeof(iNumsC2)/sizeof(int)),
             2.5, "Test Case 3");                          
    return 0;
}

void myassert(double dResult, double dExpected, char * cPtrTestName)
{
    if(dResult != dExpected)
    {
        printf("%s. ERROR: Expected %f, result =  %f\r\n",cPtrTestName, dExpected, dResult);
    }
    else
    {
        printf("%s. OK: Expected %f, result =  %f\r\n",cPtrTestName, dExpected, dResult);
    }
}

