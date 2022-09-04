#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
    Given a signed 32-bit integer x, return x with its digits reversed. 
    If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, 2^31 - 1], then return 0.

    Assume the environment does not allow you to store 64-bit integers (signed or unsigned).
*/
void myassert(int iResult, int iExpected, char * cPtrTestName);
static char *i2a(unsigned i, char *a, unsigned r)
{
    if (i / r > 0)
        a = i2a(i / r, a, r);
    *a = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[i % r];
    return a + 1;
}
bool checkAsciiIntOverFlow(char * cPtr, int sign) //sign 1 for pos, -1 for neg
{
    char *cPosArr="2147483647";
    char *cNegArr="2147483648";
    char * cArr;
    cArr = sign == 1 ? cPosArr : cNegArr;
    for(int i=0; i<10;i++)
    {
        if(cPtr[i] > cArr[i])
        {
            return true; //overflow
        }
        else if(cPtr[i] < cArr[i])
        {
            return false;
        }
    }
    return true;
}
int reverse(int x)
{
    int iResult = 0;
    unsigned int iXcpy = x;
    char cBuffer[16]={0};
    char cBufferRev[16] = {0};
    int iStrLen;
    if(x < 0){ //convert it to pos
        iXcpy *= -1; 
    }else if(x==0){
        return 0;
    }
    i2a(iXcpy,cBuffer,10); //convert to string
    //reverse the string
    iStrLen = strlen(cBuffer);
    for(int i = 0 ; i < iStrLen; i++)
    {
        cBufferRev[i] = cBuffer[iStrLen-i-1];
    }
    //check overflow or not
     if(x<0 && iStrLen > 9)
    { //neg
        if(checkAsciiIntOverFlow(cBufferRev,-1) == true) return 0;
    }
    else if(x > 0 && iStrLen > 9)
    {
        if(checkAsciiIntOverFlow(cBufferRev,1) == true) return 0;
    }

    iResult = atoi(cBufferRev); //convert string back to int
    if(x<0) iResult *= -1;
    
    return iResult;
}

int main(void)
{
    myassert(reverse(123),321,"Test case 1");
    myassert(reverse(-123),-321,"Test case 2");
    myassert(reverse(120),21,"Test case 3");     
    myassert(reverse(1534236469),0,"Test case 4");
    myassert(reverse(-2147483412),-2143847412,"Test case 5"); 
    myassert(reverse(1563847412),0,"Test case 6");
    myassert(reverse(563847412),214748365,"Test case 7");
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

