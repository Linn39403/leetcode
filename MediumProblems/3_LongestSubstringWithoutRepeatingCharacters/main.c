#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#define DEBUG 
/*
    Given a string s, find the length of the longest substring without repeating characters.
*/
void myassert(int iResult, int iExpected, char * cPtrTestName);

int lengthOfLongestSubstring(char * s)
{
    int iAns = 1;
    int iCnt = 1;
    int jStarVal = 0;
    int iStrLen = strlen(s);
    /* if the length is 0 or 1, return original str len.*/
    if(iStrLen < 2) return iStrLen; 
    bool bFoundNewChar = false;
    
    #ifdef DEBUG
        char CTemp[10] = "";
        char * cPtr = &CTemp[0];
    #else
        char * cPtr = calloc(iStrLen, sizeof(char));
    #endif

    *cPtr = s[0];
    for(int i = 1 ; i < iStrLen; i++)
    {
        iCnt = 1;
        for(int j = jStarVal; j < i; j++)
        {
            if( s[i] == s[j]) //two characters are identical, no need to check anymore
            {
                //check if i and j are adjacent each other or not
                jStarVal = ((i-1)==j) ? i : (j+1);
                // if((i-1)==j)
                // {
                //     jStarVal = i;
                // }
                // else
                // {
                //     jStarVal = j+1;
                // }
                break;
            }
            iCnt++;            //count if this two are not identical
            iAns = iCnt > iAns ? iCnt : iAns; //take the max 
        }
    }
    
    #ifndef DEBUG
    free(cPtr);
    #endif
    return iAns;
}

const char * ccPtrStr1 = "abcabcbb";
const char * ccPtrStr2 = "bbbb";
const char * ccPtrStr3 = "pwwkew";
const char * ccPtrStr4 = "geeksforgeeks"; 
const char * ccPtrStr5 = "dvdf"; 
const char * ccPtrStr6 = "anviaj";

int main(void)
{
    myassert(lengthOfLongestSubstring((char*)ccPtrStr1),3,"Test case 1");
    myassert(lengthOfLongestSubstring((char*)ccPtrStr2),1,"Test case 2");
    myassert(lengthOfLongestSubstring((char*)ccPtrStr3),3,"Test case 3");        
    myassert(lengthOfLongestSubstring((char*)ccPtrStr4),7,"Test case 4");
    myassert(lengthOfLongestSubstring((char*)ccPtrStr5),3,"Test case 5");     
    myassert(lengthOfLongestSubstring((char*)ccPtrStr6),5,"Test case 6");         
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

