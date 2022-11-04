#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


bool backspaceCompare(char * s, char * t)
{
    int sLen = strlen(s), tLen = strlen(t);
    char sArr[201] = {0};
    char tArr[201] = {0};
    int j = 0;
    bool bAns = false;
    for(int i=0; i<sLen; i++){
        if(s[i] != '#'){
            sArr[j++]=s[i];
        }else{
            if(j>0)  sArr[--j]=0;
        }
    }
    j=0;
    for(int i=0; i<tLen; i++){
        if(t[i] != '#'){
            tArr[j++]=t[i];
        }else{
            if(j>0)  tArr[--j]=0;
        }
    }
    bAns = strcmp(sArr,tArr) == 0 ? true : false;
    return bAns;
}


void myassert(bool bResult, bool bExpected, char * cPtrTestName);
int main(void)
{        
    myassert(backspaceCompare("ab#c","ad#c"),true,"Test Case 1.");
    myassert(backspaceCompare("ab##","c#d#"),true,"Test Case 2.");
    myassert(backspaceCompare("a#c","b"),false,"Test Case 3.");
    myassert(backspaceCompare("xywrrmp","xywrrmu#p"),true,"Test Case 4.");
    return 0;
}

void myassert(bool bResult, bool bExpected, char * cPtrTestName)
{
    if(bResult != bExpected)
    {
        printf("%s. ERROR: Expected %d, result =  %d\r\n",cPtrTestName, bExpected, bResult);
    }
    else
    {
        printf("%s. OK: Expected %d, result =  %d\r\n",cPtrTestName, bExpected, bResult);
    }
}
