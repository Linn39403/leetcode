
#include <iostream>
#include <stack>
#include <string>

using namespace std;
/*
    Given a balanced parentheses string s, return the score of the string.
    The score of a balanced parentheses string is based on the following rule:
    "()" has score 1.
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.
    
    Constraints:
    2 <= s.length <= 50
    s consists of only '(' and ')'.
    s is a balanced parentheses string.    
*/
void myassert(int iResult, int iExpected, string printStr);
class Solution {
public:
    int scoreOfParentheses(string s) {
        int score = 0;
        int layers = 0;
        for(int i=0; i < s.length(); i++)
        {
            layers =( s[i] == '(' ) ? ++layers : --layers;
            if(s[i] == ')' && s[i-1] == '('){
                score += ( 1 << layers ); 
            }
        }
        return score;
    }
};

Solution mySol;
int main(void)
{    
    myassert(mySol.scoreOfParentheses("()"),1,"Test Case 0"); 
    myassert(mySol.scoreOfParentheses("(())"),2,"Test Case 1"); 
    myassert(mySol.scoreOfParentheses("()()"),2,"Test Case 2");
    myassert(mySol.scoreOfParentheses("(()(()))"),6,"Test Case 3"); 
    return 0;
}

void myassert(int iResult, int iExpected, string printStr)
{
    if(iResult != iExpected)
    { 
        cout << "ERROR: Expected " << iExpected << ", result = " << iResult << ", " << printStr << std::endl;
    }
    else
    {
        cout << "OK " << printStr << std::endl;
    }
}

