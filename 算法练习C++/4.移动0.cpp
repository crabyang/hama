#include <vector>
#include <iostream>
using namespace std;



class Solution {
public:
    void moveZeroes(vector<int>& nums) {

        int pointer_fast = 0;
        int pointer_slow = 0;

        while (pointer_fast < nums.size()) {
            if (nums[pointer_fast] != 0) {
                nums[pointer_slow] = nums[pointer_fast];
                pointer_slow++;
            }
            pointer_fast++; //注意快指针是一直往前走的
        }

        while (pointer_slow < nums.size()) {
            nums[pointer_slow] = 0;
            pointer_slow++;
        }
    }
};

//int main() {
//    Solution solution;
//    vector<int> test = { 0,1,0,3,12 };
//    solution.moveZeroes(test);
//    
//    for (int num : test) {
//        cout << num << endl;
//    }
//}