#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <assert.h>

/*
    A valid number can be split up into these components (in order):

    1. A decimal number or an integer.
    2.(Optional) An 'e' or 'E', followed by an integer.
    
    A decimal number can be split up into these components (in order):
    1.(Optional) A sign character (either '+' or '-').
    2.One of the following formats:
        1.One or more digits, followed by a dot '.'.
        2.One or more digits, followed by a dot '.', followed by one or more digits.
        3.A dot '.', followed by one or more digits.
    An integer can be split up into these components (in order):

    1.(Optional) A sign character (either '+' or '-').
    2.One or more digits.
    For example, all the following are valid numbers: 
    ["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"], 
    while the following are not valid numbers: 
    ["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"].

    Given a string s, return true if s is a valid number.

    Constraints:

    1 <= s.length <= 20
    s consists of only English letters (both uppercase and lowercase), digits (0-9), plus '+', minus '-', or dot '.'.
*/

void myassert(bool bResult, bool bExpected, char * cPtrTestName);

bool isNumber(char *s)
{
    //skip the leading whitspaces
    //while(*s == ' '){ s++; };

    //check the sign 
    if(*s == '+' || *s == '-') s++;

    //check digit ( int part)
    bool hasDigit = false;
    while(*s>='0' && *s<='9'){
        hasDigit = true;
        s++;
    }

    //check optional dicimal point and digits after it
    if(*s == '.'){
        s++;
        while(*s>='0' && *s<='9'){
            hasDigit = true;
            s++;
        }
    }

    if(hasDigit == false) return false;

    //check for 'e'
    if(*s == 'e' || *s == 'E'){
        s++;
        //check for sign 
        if(*s=='+' || *s=='-') s++;

        bool hasExpDigits = false;
        while(*s>='0' && *s<='9'){
            hasExpDigits = true;
            s++;
        }
        if(hasExpDigits == false) return false;
    }

    //skip white sapces
    //while(*s == ' '){ s++; };
    // Ensure we've reached the end of the string
    return *s == '\0';
}


bool myassert_bool = true;
int main(void)
{
    #if 1
    myassert(isNumber("0"), true, "Test Case 0");
    myassert(isNumber("e"), false,"Test Case 1");
    myassert(isNumber("."), false,"Test Case 2");
    myassert(isNumber("2"), true,"Test Case 3");
    myassert(isNumber("0089"),true, "Test Case 4" );
    myassert(isNumber("-0.1"),true, "Test Case 5" );
    myassert(isNumber("+3.14"),true, "Test Case 6" );
    myassert(isNumber("4."),true, "Test Case 7" );
    myassert(isNumber("-.9"),true, "Test Case 8" );
    myassert(isNumber("2e10"),true, "Test Case 9" );
    myassert(isNumber("-90E3"),true, "Test Case 10" );
    myassert(isNumber("3e+7"),true, "Test Case 11" );
    myassert(isNumber("+6e-1"),true, "Test Case 12" );
    myassert(isNumber("53.5e93"),true, "Test Case 13" );
    myassert(isNumber("-123.456e789"),true, "Test Case 14" );
    myassert(isNumber("abc"), false, "Test Case 15");
    myassert(isNumber("1a"), false, "Test Case 16");
    myassert(isNumber("1e"), false, "Test Case 17");
    myassert(isNumber("e3"), false, "Test Case 18");
    myassert(isNumber("99e2.5"), false, "Test Case 19");
    myassert(isNumber("--6" ), false, "Test Case 20");
    myassert(isNumber("-+3"), false, "Test Case 21");
    myassert(isNumber("95a54e53"), false,"Test Case 22");
    myassert(isNumber(".1"), true,"Test Case 23");
    myassert(isNumber(".."), false,"Test Case 24");   
    myassert(isNumber(".e1"), false,"Test Case 25");
    myassert(isNumber("..2"), false,"Test Case 26");   
    myassert(isNumber("0.."), false,"Test Case 27");   
    myassert(isNumber(".1."), false,"Test Case 28");
    myassert(isNumber("6+1"), false,"Test Case 29");
    myassert(isNumber(".8+"), false,"Test Case 30");
    myassert(isNumber("3-2"), false,"Test Case 31");
    myassert(isNumber("0-"), false,"Test Case 32");
    myassert(isNumber("4e+"), false,"Test Case 33");
    myassert(isNumber("+."), false,"Test Case 34");
    myassert(isNumber("+E3"), false,"Test Case 35");
    myassert(isNumber("6ee69"), false,"Test Case 36");
    #endif

    if(myassert_bool == true){
        printf("\r\n ********************** \r\n YAYYY all test cases are passed \r\n ********************** ");
    }
    return 0;
}

void myassert(bool bResult, bool bExpected, char * cPtrTestName)
{
    if(bResult != bExpected)
    {
        myassert_bool = false;
        printf(">>>> %s. ERROR: Expected %d, result =  %d <<<<\r\n",cPtrTestName, bExpected, bResult);
    }
    else
    {
        printf("%s. OK: Expected %d, result =  %d\r\n",cPtrTestName, bExpected, bResult);
    }
}



