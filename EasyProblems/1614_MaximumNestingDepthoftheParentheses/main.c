#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))

int maxDepth(char * s)
{
    int iAns = 0;
    int iParenthesesCnt = 0;
    int iLen = strlen(s);
    if(iLen==1) return iAns;

    for(int i=0;i<iLen;i++)
    {
        if(s[i] == '(') iParenthesesCnt++;
        else if(s[i] == ')')  iParenthesesCnt--;
        iAns = max(iParenthesesCnt,iAns);
    }
    return iAns;
}



void myassert(int iResult, int iExpected, char * cPtrTestName);

int main(void)
{        
    myassert(maxDepth("(1+(2*3)+((8)/4))+1"),3,"Test Case 1");
    myassert(maxDepth("(1)+((2))+(((3)))"),3,"Test Case 2");
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

