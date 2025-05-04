#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> location;
        size_t index = 0;
        for (auto& num : nums) {
            //location[num] = index;  //给定Hash的键值对,每一次要先查找，然后再把数据放入到Hash表中
            
                if ((location.find(target - num) != location.end()) && location[target-num]!=index)
                {
                    //一遍装入一遍查找，不需要全部放入了以后才能查找，这样可以有动态的思维
                    int  ans2 = location[(target - num)];
                    vector<int> ans = {(int)index,ans2 };
                    return ans;
                }
                location[num] = (int)index;  //给定Hash的键值对
                index++;   //注意index++的代码位置，要在我们使用了当前的全部的index后才能去将我们的循环变量进行修改
                
        }

        return {};



    }
};

//#ifdef Main1
//int main() {
//    Solution solution;
//    vector<int> nums = { 3,3 };
//    int target = 6;
//    vector<int> result = solution.twoSum(nums, target);
//    if (result.empty() == false) {
//        cout << "答案为：" << target << "are:" << result[0] << "and" << result[1] << endl;
//
//    }
//    else
//    {
//        cout << "No solution found." << endl;
//
//
//    }
//
//    return 0;
//
//}
//#endif

