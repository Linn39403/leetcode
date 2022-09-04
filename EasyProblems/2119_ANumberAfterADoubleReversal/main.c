#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
    Reversing an integer means to reverse all its digits.
    For example, reversing 2021 gives 1202. Reversing 12300 gives 321 as the leading zeros are not retained.
    Given an integer num, reverse num to get reversed1, then reverse reversed1 to get reversed2. 
    Return true if reversed2 equals num. Otherwise return false.
*/
void myassert(bool iResult, bool iExpected, char * cPtrTestName);
static char *i2a(unsigned i, char *a, unsigned r)
{
    if (i / r > 0)
        a = i2a(i / r, a, r);
    *a = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i % r];
    return a + 1;
}

bool isSameAfterReversals(int num)
{
    bool bAns = false;
    char cBuffer[16] = "";
    char cBufferRev[16] = "";
    int iStrLen = 0;
    int iNumRev = 0;

    //Step1. convert to string
    i2a(num, cBuffer, 10);
    iStrLen = strlen(cBuffer);
    
    //Step2. reverse the string and convert back to int ( Reversed )
    for(int i = 0 ; i < iStrLen; i++)
    {
        cBufferRev[i] = cBuffer[iStrLen-i-1];
    }
    iNumRev = atoi(cBufferRev);

    //Step3. convert reversed int to string
    memset(cBuffer, 0, 10);
    memset(cBufferRev, 0, 10);
    i2a(iNumRev, cBuffer, 10);
    iStrLen = strlen(cBuffer);

    //Step4. reverse again and convert back to int 
    for(int i = 0 ; i < iStrLen; i++)
    {
        cBufferRev[i] = cBuffer[iStrLen-i-1];
    }
    iNumRev = atoi(cBufferRev);

    bAns = iNumRev == num ? true : false;

    return bAns;
}

int main(void)
{
    myassert(isSameAfterReversals(526),true,"Test case 1");
    myassert(isSameAfterReversals(1800),false,"Test case 2");
    myassert(isSameAfterReversals(0),true,"Test case 3");
    return 0;
}

void myassert(bool iResult, bool iExpected, char * cPtrTestName)
{
    if(iResult != iExpected)
    {
        printf("%s: ERROR\r\n",cPtrTestName);
    }
    else
    {
        printf("%s: OK\r\n",cPtrTestName);
    }
}

