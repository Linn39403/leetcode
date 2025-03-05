/******************************************************************************


Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.

*******************************************************************************/
#include <iostream>
#include <vector>
void testAnswer(const std::vector<int>& ans, const int expected[], size_t size);
std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) 
{
  int r_top, r_bot, c_left, c_right;
  r_top = 0;
  r_bot = snail_map.size() - 1;
  c_left = 0;
  c_right = snail_map[0].size() - 1;
  std::vector<int> ans;
  int snail_element_total = snail_map.size() * snail_map[0].size();
  do{
    for(int i=c_left; i<= c_right; i++){
        ans.push_back(snail_map[r_top][i]);
        snail_element_total--;
    }
    r_top++;
    
    for(int i=r_top; i<=r_bot; i++){
        ans.push_back(snail_map[i][c_right]);
        snail_element_total--;
    }
    c_right--;

    for(int i=c_right; i>= c_left; i--){
        ans.push_back(snail_map[r_bot][i]);
        snail_element_total--;
    }
    r_bot--;

    for(int i=r_bot; i>= r_top; i--){
        ans.push_back(snail_map[i][c_left]);
        snail_element_total--;
    }
    c_left++;
  }while(snail_element_total);
  return ans;
}

int main()
{
    std::vector<std::vector<int>> v;
    v = {{1,2,3}, {8,9,4}, {7,6,5}};
    const int ans1[] = {1,2,3,4,5,6,7,8,9}; 
    testAnswer(snail(v), ans1, sizeof(ans1)/sizeof(ans1[0]));

    v = {{1}};
    const int ans2[] = {1};
    testAnswer(snail(v), ans2, sizeof(ans2)/sizeof(ans2[0]));

    v = {{1,2}, {4,3}};
    const int ans3[] = {1,2,3,4};
    testAnswer(snail(v), ans3, sizeof(ans3)/sizeof(ans3[0]));

    v = {{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}};
    const int ans4[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
    testAnswer(snail(v), ans4, sizeof(ans4)/sizeof(ans4[0]));
    return 0;
}

void printVector(const std::vector<int>& vec) {
    for (const int& num : vec) {
        std::cout << num << " ";
    }
}

void printVector(const int arr[], size_t size, size_t wrong_idx) {
    for(int i=0; i < size; i++){
        if(wrong_idx == i){
            std::cout << '[';
        }
        std::cout << arr[i] << " ";
        if(wrong_idx == i){
            std::cout << ']';
        }
    }
}

void testAnswer(const std::vector<int>& ans, const int expected[], size_t size)
{
    bool foundDiff = false;
    size_t error_idx;
    for(int i=0; i<size; i++)
    {
        if(ans[i] != expected[i]){
            error_idx = i;
            foundDiff = true;
            break;
        }
    }
    if(foundDiff == true){
        std::cout << "WRONG at index " << error_idx << " Expected = " ;
        printVector(ans);
        std::cout << " But got = ";
        printVector(expected,size, error_idx);
        //Result = " "\"";
    }else{
        std::cout << "OK: ";
        printVector(ans);
    }
    std::cout << "\n";
}