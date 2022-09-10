#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>

/*
    Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

    The algorithm for myAtoi(string s) is as follows:

    Read in and ignore any leading whitespace.
    Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
    Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
    Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
    If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
    Return the integer as the final result.
    
    Note:
    Only the space character ' ' is considered a whitespace character.
    Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
*/
void myassert(int iResult, int iExpected, char * cPtrTestName);

char * skipWhiteSpaceAndLeadingZeros(char * s)
{
    char * ptAns = s;
    /* if first byte is not space, just return */
    if(*ptAns != ' ' && *ptAns != '0') return ptAns; 

    while(*ptAns == ' ' || *ptAns == '0')
    {
        ptAns++;
    }
        
    return ptAns;
}

char * removeText(char * s)
{
    static char scArr[201];
    bool bIsThisTextInBetweenTheDigit = false;
    memset(scArr,0, sizeof(scArr));
    int iStrLen = strlen(s);
    int j = 0;
    for(int i = 0 ; i < iStrLen; i++)
    {
        if(isdigit(s[i]))
        {
            if(s[i] == '0' && scArr[0] == 0)
            {

            }
            else
            {
                 scArr[j++] = s[i];
            }
            bIsThisTextInBetweenTheDigit = true;
        }
        else if(bIsThisTextInBetweenTheDigit == true)
        {   //want to catch the text in between the digits 
            // for example 3.14156
            //              ^  
            if(s[i]=='.' || s[i] == ' ')   
                return (char*)&scArr[0];        
            else
            {
                return (char*)&scArr[0];
            }
        }
    }
    return (char*)&scArr[0];
}

long long convertStrToLong(char * s)
{
    int iStrLen = strlen(s);
    long long llResult = 0;
    for(int i = 0 ; i < iStrLen; i++)
    {
        llResult += (s[i] - '0') * pow(10,iStrLen-i-1);
    }
    return llResult;
}

int myAtoi(char * s)
{
    int iStrLen = strlen(s);
    if(iStrLen == 0) return 0;
    
    long long  llResult = 0;
    int iSign = 1; //1 for pos, -1 for neg

    //char * pt = skipWhiteSpaceAndLeadingZeros(s); //Step1 
    
    if(*s == ' ') //skip white space
    {
        while(*s == ' ')
            s++;
    }

    char * pt = s;
    if(*s == '0') //skip zeros
    {
        while(*s == '0')
        {
            s++;
        }
         if(*pt == '-' || *pt == '+' || isalpha(*pt) == true )
            return 0;
    }
    //Step2
    if(*pt == '-')
    {
        iSign = -1;
        pt++;
    }
    else if(*pt == '+' && isalpha(*pt) == false )
    {
        pt++;
    }
    
    //Step3 
    if(isdigit(*pt) == false) return 0; //invalid characters
    pt = removeText(pt);             

    //check the digit length if it's more t  than 10 digit, no need to calculate 
    if(strlen(pt) > 10 )
    {
        llResult = iSign == 1 ? 0x7FFFFFFF : 0x80000000;
        return (int)llResult;
    }
    llResult = convertStrToLong(pt);   //Step4
    //step6
    if(iSign == 1) //pos
    {
        if( llResult >= 0x7FFFFFFF ) llResult = 0x7FFFFFFF;
    }
    else //neg
    {
        if(llResult >= 0x80000000 ) 
        {
            llResult = 0x80000000;
        }
        else
        {
            llResult *= -1;
        }
    }
    return (int)llResult;
}

char * cptr1 = "    -42";
char * cptr2 = "4193 with words";
char * cptr3 = "words and 987";
char * cptr4 = "3.14159";
char * cptr5 = "+-12";
char * cptr6 = "21474836460";
char * cptr7 = "20000000000000000000";
char * cptr8 = "  0000000000012345678";
char * cptr9 = "00000-42a1234";
char * cptr10 = "-000000000000001";
char * cptr11 = "  -0012a42";
int main(void)
{
    myassert(myAtoi(cptr1),-42,"Test1");
    myassert(myAtoi(cptr2),4193,"Test2");
    myassert(myAtoi(cptr3),0,"Test3");    
    myassert(myAtoi(cptr4),3,"Test4");      
    myassert(myAtoi(cptr5),0,"Test5");    
    myassert(myAtoi(cptr7),2147483647,"Test7");    
    myassert(myAtoi(cptr8),12345678,"Test8");     
    myassert(myAtoi(cptr9),0,"Test9");    
    myassert(myAtoi(cptr10),-1,"Test10");   
    myassert(myAtoi(cptr11),-12,"Test11");        
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

