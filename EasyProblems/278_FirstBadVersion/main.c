#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
void myassert(int iResult, int iExpected, char * cPtrTestName);
bool isBadVersion(int version)
{
    if(version >= 4) return true;
    return false; 
}

int firstBadVersion(int n) 
{
    int low = 1, high = n;
    int mid = 0; 
    int iAns = 1;
    while ( low <= high)
    {
        mid = low + ( high - low ) / 2;
        if(isBadVersion(mid) == true ){
            iAns = mid;
            high = mid - 1;
        }else{
            low = mid + 1;
        }
    }

    return iAns;
    
}

int main(void)
{
    myassert(firstBadVersion(5000),4,"Test Case 1");
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

