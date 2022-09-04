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
int hammingWeight(uint32_t n) 
{
    uint32_t u32Ans = 0;
    uint32_t u32Ncpy = n;
    int i = 31;
    while(i-- >= 0)
    {
        if(u32Ncpy & 0x01)
        {
            u32Ans ++;
        }
        u32Ncpy >>= 1;        
    }
    return u32Ans;
}

int main(void)
{
    myassert(hammingWeight(11),3,"Test case 1");
    myassert(hammingWeight(128),1,"Test case 2");    
    myassert(hammingWeight(4294967293),31,"Test case 3");
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



