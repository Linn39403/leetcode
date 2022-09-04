#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
/*
    Reverse bits of a given 32 bits unsigned integer.
*/
void myassert(uint32_t iResult, uint32_t iExpected, char * cPtrTestName);
uint32_t reverseBits(uint32_t n) 
{
    uint32_t u32Ans = 0;
    uint32_t u32Ncpy = n;

    for(int i=0; i < 32; i++)
    {
        if(u32Ncpy & 0x01)
        {
            u32Ans +=  ((uint32_t)(1) << (31-i));
        }
        u32Ncpy >>= 1;        
    }
    return u32Ans;
}

int main(void)
{
    myassert(reverseBits(43261596),964176192,"Test case 1");
    myassert(reverseBits(4294967293),3221225471,"Test case 2");    
    return 0;
}

void myassert(uint32_t iResult, uint32_t iExpected, char * cPtrTestName)
{
    if(iResult != iExpected)
    {
        printf("%s. ERROR: Expected %u, result =  %u\r\n",cPtrTestName, iExpected, iResult);
    }
    else
    {
        printf("%s. OK: Expected %u, result =  %u\r\n",cPtrTestName, iExpected, iResult);
    }
}



