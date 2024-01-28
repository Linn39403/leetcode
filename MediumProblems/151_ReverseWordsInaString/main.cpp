#include <iostream>
#include <assert.h>
#include <string>
/*
    Given an input string s, reverse the order of the words.
    A word is defined as a sequence of non-space characters. 
    The words in s will be separated by at least one space.
    Return a string of the words in reverse order concatenated by a single space.
    Note that s may contain leading or trailing spaces or multiple spaces between two words. 
    The returned string should only have a single space separating the words. 
    Do not include any extra spaces.
*/
using namespace std;
class Solution {
public:
    string reverseWords(string s) 
    {
        string sAns = "";
        string subString = "";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == ' ')
            {
                if(subString.length() != 0 ) //there is something inside the subString
                {
                    if(sAns.length() != 0)
                    {
                        sAns = subString + ' ' + sAns;
                    }
                    else
                    {
                        sAns = subString + sAns;   
                    }
                    
                    subString = ""; //clear the substring
                }
            }
            else
            {
                subString += s.at(i);
            }
        }
        if(subString.length())
        {
            if(sAns.length() != 0)
            {
                sAns = subString + ' ' + sAns;
            }
            else
            {
                sAns = subString + sAns;   
            }
        }
        return sAns;
    }
};

void myassert(string sResult, string sExpected, string sTestName)
{
    if(sResult != sExpected)
    {
        cout << sTestName << ". ERROR: Expected \"" << sExpected << 
                "\", result = \"" << sResult << "\"" <<endl;
        
    }
    else
    {
        cout << sTestName << ". OK: Expected \"" << sExpected << 
             "\", result = \"" << sResult << "\""  << endl;
    }
}


int main(void)
{
    Solution mySol;
    myassert(mySol.reverseWords("Hello World"), "World Hello", "Test Case 1");
    myassert(mySol.reverseWords("  hello world  "), "world hello", "Test Case 2");
    myassert(mySol.reverseWords("a good   example"), "example good a", "Test Case 3");
    return 0;
}

