#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <inttypes.h>
#include <math.h>
/*
    Reverse bits of a given 32 bits unsigned integer.
*/
void myassert(bool bResult, bool bExpected, char * cPtrTestName);
bool isPowerOfTwo(int n)
{
    if(n==1) return true;
    for(int i=1;i<31;i++)
    {
        int iPowerOfTwo = (int)1 << i;
        if(n==iPowerOfTwo){
            return true;
        }else if(n < iPowerOfTwo){
            return false; //there is no more 
        }
    }
    return false;
}

int main(void)
{
    myassert(isPowerOfTwo(1),true,"Test case 1");
    myassert(isPowerOfTwo(16),true,"Test case 2");    
    myassert(isPowerOfTwo(3),false,"Test case 3");        
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



