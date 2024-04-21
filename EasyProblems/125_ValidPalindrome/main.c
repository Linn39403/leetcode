#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/*
    A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. 
    Alphanumeric characters include letters and numbers.
    Given a string s, return true if it is a palindrome, or false otherwise.
*/
bool isPalindrome(char* s) 
{
    int s_len = strlen(s);
    if(s_len==1) return true;
    char * cptr = calloc(sizeof(char), s_len+1);
    
    int cptr_idx = 0;

    for(int i = 0; i < s_len; i++)
    {
        
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            cptr[cptr_idx++] = s[i] - 'A' + 'a';
        }
        else if((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= '0' && s[i] <= '9'))
        {
            cptr[cptr_idx++] = s[i];
        }
        
    }
    s_len = strlen(cptr);
    if(s_len<=1){
        free(cptr);
        return true;
    }
    for(int i=0; i<=s_len/2;i++)
    {
        if(cptr[i] != cptr[s_len-i-1]){
            free(cptr);
            return false;
        }        
    }
    free(cptr);
    return true;
}
void myassert(bool bResult, bool bExpected, char * cPtrTestName);
int main(void)
{     
       
    myassert(isPalindrome("A man, a plan, a canal: Panama"),true,"Test Case 1");
    myassert(isPalindrome("race a car"),false,"Test Case 2");
    myassert(isPalindrome(" "),true,"Test Case 3");
    myassert(isPalindrome("a."),true,"Test Case 4");
    myassert(isPalindrome("ab@a"),true,"Test Case 5");
    myassert(isPalindrome("0P"),false,"Test Case 6");
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

