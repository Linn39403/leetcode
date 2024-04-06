#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
void myassert(char * result, char * expected, char * printStr);

/*
    Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
    Since the result may be very large, so you need to return a string instead of an integer.
    Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 10^9
*/
// Custom comparison function for qsort
int compare(const void *a, const void *b) {
    char *s1 = *(char **)a;
    char *s2 = *(char **)b;
    char *concat1 = (char *)malloc(strlen(s1) + strlen(s2) + 1);
    char *concat2 = (char *)malloc(strlen(s1) + strlen(s2) + 1);
    
    strcpy(concat1, s1);
    strcat(concat1, s2);
    
    strcpy(concat2, s2);
    strcat(concat2, s1);
    
    int result = strcmp(concat2, concat1);
    
    free(concat1);
    free(concat2);
    
    return result;
}

char* largestNumber(int* nums, int numsSize) {
    // Convert numbers to strings
    char** strNums = (char**)malloc(numsSize * sizeof(char*));
    for (int i = 0; i < numsSize; i++) {
        strNums[i] = (char*)malloc(12 * sizeof(char)); // Max number length is 10 digits
        sprintf(strNums[i], "%d", nums[i]);
    }
    
    // Sort the strings
    qsort(strNums, numsSize, sizeof(char*), compare);
    
    // If the largest number is 0, the result should be "0"
    if (strcmp(strNums[0], "0") == 0)
        return "0";
    
    // Concatenate sorted strings
    char* result = (char*)calloc(1024, sizeof(char));
    for (int i = 0; i < numsSize; i++) {
        strcat(result, strNums[i]);
        free(strNums[i]);
    }
    free(strNums);
    
    return result;
}

int main(void)
{   
    int nums_1[2] = {10,2};
    char * expected_num1 = "210";
    
    int nums_2[5] = {3,30,34,5,9};
    char * expected_num2 = "9534330";

    int nums_3[2] = {111311, 1113};
    char * expected_num3 = "1113111311";
#if 1
    myassert(largestNumber(nums_1, sizeof(nums_1)/sizeof(nums_1[0])),
             expected_num1, 
             "Test Case 1"
            );
    myassert(largestNumber(nums_2, sizeof(nums_2)/sizeof(nums_2[0])),
             expected_num2, 
             "Test Case 2"
            );           
#endif
#if 1       
    myassert(largestNumber(nums_3, sizeof(nums_3)/sizeof(nums_3[0])),
             expected_num3, 
             "Test Case 3"
            );     
#endif         
    return 0;
}
void myassert(char * result, char * expected, char * printStr)
{
    if(strcmp(result, expected) != 0)
    { 
        printf("ERROR: Expected %s, result =  %s, %s\r\n",expected, result, printStr);
    }
    else
    {
        printf("%s OK\r\n",printStr);
    }
    free(result);
}
