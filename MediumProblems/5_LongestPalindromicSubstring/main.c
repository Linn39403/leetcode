#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define DEBUG 
/*
    Given a string s, return the longest palindromic substring in s.
*/
void myassert(char * cPtrResult, const char * cCPtrExpected, char * cPtrTestName);
#if 1
char * longestPalindrome(char * s)
{
    int iResultLen = 0;
    int iStrLen = strlen(s);
    char * cptr ;
    if(iStrLen < 2)
    {
        return s;
    }
    else
    {
        cptr = calloc(iStrLen+2,sizeof(char));
    }
    for(int i = 0 ; i < iStrLen; i++)
    {
        int iLeftIdx = i, iRightIdx = i;
        int iLen;
        while(iLeftIdx >= 0 && iRightIdx < iStrLen &&
             s[iLeftIdx] == s[iRightIdx]) //odd
        {
            iLen = iRightIdx-iLeftIdx+1;
            if(iLen > iResultLen) //take max
            {
                iResultLen = iLen;
                strncpy(cptr,&s[iLeftIdx],iResultLen); 
            }
            iLeftIdx--;
            iRightIdx++;
        }    
        iLeftIdx = i; iRightIdx = i+1;
        while(iLeftIdx >= 0 && iRightIdx < iStrLen &&
            s[iLeftIdx] == s[iRightIdx]) //even
        {
            iLen = iRightIdx-iLeftIdx+1;
            if(iLen > iResultLen)
            {
                iResultLen = iRightIdx - iLeftIdx + 1;
                strncpy(cptr,&s[iLeftIdx],iResultLen); 
            }
            iLeftIdx--;
            iRightIdx++;
        }      
    }  
    return cptr;
}
#endif 
#if 0 //Failed in the "aacabdkacaa" case
char * longestPalindrome(char * s)
{
    //reverse back
    char cRevStr[1000] = "";
    int sLength = strlen(s);
    int iMaxLength = 0;
    char cTempString[1000] = "";
    static char cLongestPalindromeStr[1000];
    memset(cLongestPalindromeStr,0, 1000);
    char * cPtrResult = cLongestPalindromeStr;
    for(int i = 0 ; i < sLength; i ++)
    {
        cRevStr[i] = s[sLength-i-1];
    }
    for(int i = 0 ; i < sLength; i ++) //shift right the input string 
    {
        int iIdx, iCnt;
        char * cPtr = strchr((const char*)cRevStr, s[i]);
        if(cPtr != NULL)
        {
            iIdx = i; iCnt = 1;
            cTempString[0] = *cPtr;
            while(cPtr++ != NULL && s[iIdx++] != NULL && *cPtr == s[iIdx])
            {
                cTempString[iCnt++] = *cPtr;
            }
        }
        if(iCnt > iMaxLength)
        {
            iMaxLength = iCnt;
            strcpy(cLongestPalindromeStr, cTempString);
        }
    }
    return cPtrResult;
}
#endif 



char * cPtrStr1 = "babad";
char * cPtrStr2 = "cbbd";
char * cPtrStr3 = "aacabdkacaa";
int main(void)
{
    myassert(longestPalindrome(cPtrStr1),"bab","Test Case 1");
    myassert(longestPalindrome(cPtrStr2),"bb","Test Case 2");    
    myassert(longestPalindrome(cPtrStr3),"aca","Test Case 3");    
    return 0;
}

void myassert(char * cPtrResult, const char * cCPtrExpected, char * cPtrTestName)
{
    if(strcmp((const char*)cPtrResult,cCPtrExpected)!=0)
    {
        printf("%s. ERROR: Expected %s, result = %s\r\n",cPtrTestName, cCPtrExpected, cPtrResult);
    }
    else
    {
        printf("%s. OK: Expected %s, result = %s\r\n",cPtrTestName, cCPtrExpected, cPtrResult);
    }
}

