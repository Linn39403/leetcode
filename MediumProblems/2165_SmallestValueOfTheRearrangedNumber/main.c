#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
void myassert(long long result, long long expected, char * printStr);

/*
    You are given an integer num. Rearrange the digits of num such that its value is minimized and it does not contain any leading zeros.
    Return the rearranged number with minimal value.
    Note that the sign of the number does not change after rearranging the digits.

    Constraints:

    -10^15 <= num <= 10^15
*/
long long a2ll(int * inputIntArr, int len)
{
    long long result = 0;
    for(int i=len-1; i>-1;i--)
    {
        result += inputIntArr[len-i-1] * pow(10,i);
    }
    return result;
}

int ll2a(int * outputArray, long long InputLongLong)
{
    int OutArrIdx = 0;
    long long inputCpy = InputLongLong;
    int power;
    if(InputLongLong < 0 ){
        InputLongLong *= -1;
    }
    
    for(power = 15; power > 0; power --){
        long long temp = pow(10, power);
        if(InputLongLong >= temp){
            break;
        }
    }
    
    for(power; power > 0; power --){
        long long temp = pow(10, power);
        outputArray[OutArrIdx++] = InputLongLong / temp;
        InputLongLong %= temp;
    }
    outputArray[OutArrIdx] = InputLongLong;
    return OutArrIdx;
}
int smaller_compare(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b); 
}

int bigger_compare(const void *a, const void *b)
{
    return (*(int*)b - *(int*)a); 
}



long long smallestNumber(long long num) 
{
    int InputNum2StrArr[20] = {0};
    int length = ll2a(InputNum2StrArr, num);
    if(length < 1) return num;
    long long result = 0;
    int i = 0;
    if(num < 0){ //neg
        qsort(InputNum2StrArr, length + 1, sizeof(int), bigger_compare);
        result = a2ll(InputNum2StrArr, length+1);
        result *= -1;
    }else{
        qsort(InputNum2StrArr, length + 1, sizeof(int), smaller_compare);
        if(InputNum2StrArr[0] == 0){ //first digit is zero, replace with non zero digit
            while(InputNum2StrArr[i] == 0){
                i++;
            }
            //swap the non-zero to the index 0
            InputNum2StrArr[0] = InputNum2StrArr[i];
            InputNum2StrArr[i] = 0;
        }
        result = a2ll(InputNum2StrArr, length+1);
    }

    return result;
}
int main(void)
{   
    myassert(smallestNumber(301), 103, "Test Case 01");
    myassert(smallestNumber(-7605), -7650, "Test Case 02");
    myassert(smallestNumber(95005), 50059, "Test Case 03");
    for(int i = 0; i < 10; i++){
        myassert(smallestNumber(i), i, "Test Case 04");
    }
    
    
    return 0;
}
void myassert(long long result, long long expected, char * printStr)
{
    if( result != expected)
    { 
        printf("ERROR: Expected %lld, result =  %lld, %s\r\n",expected, result, printStr);
    }
    else
    {
        printf("%s OK\r\n",printStr);
    }
}
