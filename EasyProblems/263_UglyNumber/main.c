#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
    An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
    Given an integer n, return true if n is an ugly number.
*/

bool isUgly(int n)
{
    bool bFlag = false;
    if (n == 1) return true;
    if (n == 0) return false;
    if(n%2 == 0) {
         n /= 2;  bFlag = true; 
    }
    if(n%3 == 0) { 
        n /= 3;  bFlag = true; 
    }
    if(n%5 == 0) {
        n /= 5;  bFlag = true; 
    }
    return(( bFlag == true ) ? isUgly(n) : false );
}

void myassert(bool bResult, bool bExpected, char * cPtrTestName);
int main(void)
{        
    myassert(isUgly(6),true,"Test Case 1");
    myassert(isUgly(1),true,"Test Case 2");
    myassert(isUgly(14),false,"Test Case 3");
    myassert(isUgly(8),true,"Test Case 3");
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

