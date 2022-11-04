#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
/*
    You are given a string s, which contains stars *.

    In one operation, you can:

    Choose a star in s.
    Remove the closest non-star character to its left, as well as remove the star itself.
    Return the string after all stars have been removed.
*/

char * removeStars(char * s)
{
    int sLen = strlen(s);
    char * cptr = (char*) calloc(sLen+1, sizeof(char));
    
    for(int i=0,j=0;i<sLen;i++)
    {
        if(s[i]!='*'){
            cptr[j++] = s[i];
        }else{
            if(j>0) cptr[--j]=0;
        }
    }
    return cptr;
}


void myassert(char * sResult, char * sExpected, char * cPtrTestName);
int main(void)
{        
    myassert(removeStars("leet**cod*e"),"lecoe","Test Case 1");
    myassert(removeStars("erase*****"),"","Test Case 2");
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
