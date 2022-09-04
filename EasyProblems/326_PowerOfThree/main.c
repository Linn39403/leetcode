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
bool isPowerOfThree(int n)
{
    if(n==1) return true;
    for(int i=1;i<31;i++)
    {
        int iPowerOfThree = pow(3,i);
        if(n==iPowerOfThree){
            return true;
        }else if(n < iPowerOfThree){
            return false; //there is no more 
        }
    }
    return false;
}

int main(void)
{
    myassert(isPowerOfThree(27),true,"Test case 1");
    myassert(isPowerOfThree(0),false,"Test case 2");    
    myassert(isPowerOfThree(-1),false,"Test case 3");        
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



