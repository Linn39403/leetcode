
#include <iostream>
#include <stack>
#include <string>
#include <limits>
#include <vector>

using namespace std;
/*
    Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.
    The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.
    
    Constraints:
        2 <= nums.length <= 1000
        1 <= nums[i] <= 1000
*/

void myassert(int iResult, int iExpected, string printStr);
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int iMin = INT_MAX, iMax = 0;
        for(int i=0; i < nums.size(); i++){
            if(nums[i] > iMax ){
                iMax = nums[i];
            }
            if(nums[i] < iMin){
                iMin = nums[i];
            }
        }
        return GCD(iMin,iMax);        
    }

    int GCD(int x, int y)
    {
        int rem = x%y;
        if(rem == 0)
            return y;
        else
            return(GCD(y, rem));
    }
};

Solution mySol;

vector<int> vector1 = {2,5,6,9,10};
vector<int> vector2 = {7,5,6,8,3};
vector<int> vector3 = {3,3};
int main(void)
{    
    myassert(mySol.findGCD(vector1),2,"Test Case 0"); 
    myassert(mySol.findGCD(vector2),1,"Test Case 1"); 
    myassert(mySol.findGCD(vector3),3,"Test Case 2"); 
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

