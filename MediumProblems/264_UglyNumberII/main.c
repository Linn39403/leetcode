#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*
    An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
    Given an integer n, return the nth ugly number.
*/
void myassert(int iResult, int iExpected, char * cPtrTestName);
#define MIN(a,b)        ((a)<(b)?(a):(b))
#define MIN_3(a,V...)   MIN(a,MIN(V))
#if 1
int iArr[12] = {0};
int nthUglyNumber(int n)
{
    int iResult = 1;
    int iNum2 = 2, iNum3 = 3, iNum5 = 5;
    int iNum2Idx = 0, iNum3Idx = 0, iNum5Idx = 0;
    if( n == 1 ) return 1;
    int *iPtr = (int*) malloc(sizeof(int)*n);
    iPtr[0] = 1;
    printf("\r\n");

    for(int i=1; i<n; i++)
    {
        iResult = MIN_3(iNum2,iNum3,iNum5);
        iPtr[i] = iResult;
        printf(" %d", iResult);
        if( iResult == iNum2 ){
            iNum2 = 2 * iPtr[++iNum2Idx];
        }
        if( iResult == iNum3 ){           
            iNum3 = 3 * iPtr[++iNum3Idx];
        }
        if( iResult == iNum5 ){
            iNum5 = 5 * iPtr[++iNum5Idx];    
        }        
    }
    printf("\r\n");
    free(iPtr);
    return iResult;
}
#endif

int main(void)
{
    myassert(nthUglyNumber(10),12,"Test Case 0");
    myassert(nthUglyNumber(11),15,"Test Case 1");
    myassert(nthUglyNumber(1),1,"Test Case 2");
    myassert(nthUglyNumber(3),3,"Test Case 3");
    return 0;
}

void myassert(int iResult, int iExpected, char * cPtrTestName)
{
    if(iResult != iExpected)
    {
        printf("%s. ERROR: Expected %d, result =  %d\r\n",cPtrTestName, iExpected, iResult);
    }
    else
    {
        printf("%s. OK: Expected %d, result =  %d\r\n",cPtrTestName, iExpected, iResult);
    }
}

