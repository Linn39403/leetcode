#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

/**
    You are given a string s that consists of lower case English letters and brackets.
    Reverse the strings in each pair of matching parentheses, starting from the innermost one.
    Your result should not contain any brackets.

    Constraints:

    1 <= s.length <= 2000
    s only contains lower case English characters and parentheses.
    It is guaranteed that all parentheses are balanced.
 */
void myassert(char * sResult, char * sExpected, char * cPtrTestName);
char* reverseParentheses(char* s) 
{
    int len = strlen(s);
    char *ansArr = (char *)calloc(2001, sizeof(char));
    //char testArr[20] = {0};
    //char * ansArr = testArr;
    int ansArrIdx = 0;
    char stkArr[20] = {0};
    int stkArrIdx = 0;
    for(int i = 0 ; i < len; i++)
    {
        if(s[i] != ')')
        {
            ansArr[ansArrIdx++] = s[i];
        }
        else
        {
            ansArrIdx--;
            if(ansArr[ansArrIdx] == '(') // found empty parthesiss break the loop
            {
                ansArr[ansArrIdx] = 0;
                goto skip_loop;
            }
            do
            {
                if(ansArr[ansArrIdx] != '('){
                    stkArr[stkArrIdx++] = ansArr[ansArrIdx];
                }
                ansArr[ansArrIdx] = 0x00;
                ansArrIdx--;
            } while (ansArrIdx > -1 && ansArr[ansArrIdx] != '(');
            //put it back to ansArr ( must be reverse way)
            int stkLen = strlen(stkArr);
            if(ansArrIdx == -1 ) ansArrIdx = 0;
            
            for(int j = 0 ; j < stkLen; j++)
            {
                ansArr[ansArrIdx++] = stkArr[j];
            }
            memset(stkArr,0,sizeof(stkArr)/sizeof(stkArr[0]));
            
skip_loop:
            stkArrIdx = 0;
        }
    }
    return ansArr;
}
int main(void)
{   
    myassert(reverseParentheses("(ed(et(oc))el)"), "leetcode", "test case 1");
    myassert(reverseParentheses("(u(love)i)"), "iloveu", "test case 2");
    myassert(reverseParentheses("(abcd)"), "dcba", "test case 3");
    myassert(reverseParentheses("a(bcdefghijkl(mno)p)q"), "apmnolkjihgfedcbq", "test case 4");
    myassert(reverseParentheses("vdgzyj()") , "vdgzyj" , "test case 5");

    return 0;
}


void myassert(char * sResult, char * sExpected, char * cPtrTestName)
{
    if(strcmp(sResult,sExpected) != 0)
    {
        printf("%s. ERROR: Expected %s, result =  %s\r\n",cPtrTestName, sExpected, sResult);
    }
    else
    {
        printf("%s. OK: Expected %s, result =  %s\r\n",cPtrTestName, sExpected, sResult);
    }
}
