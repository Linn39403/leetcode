#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
/*
    Given a positive integer, check whether it has alternating bits: namely,
    if two adjacent bits will always have different values.
*/
void myassert(bool bResult, bool bExpected, char * cPtrTestName);
bool hasAlternatingBits(int n)
{
    if(n==1) return true;
    char cPosBitVal = n & 0x01;
    int iTemp = n;
    while(iTemp > 0)
    {
        iTemp >>= 1;
        int iLSB = iTemp & 0x01;
        if( cPosBitVal != iLSB)
        {
            cPosBitVal = iLSB;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main(void)
{
    myassert(hasAlternatingBits(5),true,"Test case 1");
    myassert(hasAlternatingBits(7),false,"Test case 2");    
    myassert(hasAlternatingBits(11),false,"Test case 3");        
    return 0;
}

void myassert(bool bResult, bool bExpected, char * cPtrTestName)
{
    if(bResult != bExpected)
    {
        printf("%s: ERROR\r\n",cPtrTestName);
    }
    else
    {
        printf("%s: OK\r\n",cPtrTestName);
    }
}



