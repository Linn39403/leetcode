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
bool isPowerOfFour(int n)
{
    if(n==1) return true;
    for(int i=1;i<31;i++)
    {
        int iPowerOfFour = pow(4,i);
        if(n==iPowerOfFour){
            return true;
        }else if(n < iPowerOfFour){
            return false; //there is no more 
        }
    }
    return false;
}

int main(void)
{
    myassert(isPowerOfFour(16),true,"Test case 1");
    myassert(isPowerOfFour(5),false,"Test case 2");    
    myassert(isPowerOfFour(1),true,"Test case 3");        
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



