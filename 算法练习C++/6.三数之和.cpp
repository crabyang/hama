#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//下面的代码是第一版，功能是实现了的，但是没有实现去重！去重其实是这道题的一个关键的一个考点！
// 
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        unordered_map<int, vector<int>> map; //一种值和所有的对应的下标的
//        vector<vector<int>> ans;
//        
//
//        for (int i = 0; i < nums.size(); i++) {
//            if (map.find(nums[i]) != map.end()) {
//                //持续装入
//                map[nums[i]].push_back(i);
//            }
//            else
//            {
//                //初始化
//                vector<int> c = { i };
//                map[nums[i]] = c;
//            }
//        }
//
//
//        for (int i = 0; i < nums.size(); i++) {
//            for (int j = i + 1; j < nums.size(); j++) {
//                int complement = 0 - nums[i] - nums[j];  //遍历所有的二元组
//                if (map.find(complement)!=map.end()) {
//                    vector<int> list = map[complement];
//                    for (int num : list) {
//                        if (num != i && num != j  && j<num) {
//                            vector<int> one_ans = { nums[i],nums[j],nums[num] };
//                            ans.push_back(one_ans);
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//
//        return ans;
//    }
//};

//int main() {
//    Solution solution;
//    vector<int> test = { -1,0,1,2,-1,-4 };
//    vector<vector<int>> ans = solution.threeSum(test);
//    for (vector<int> one_ans : ans) {
//        for (int i = 0; i < 3; i++) {
//            cout << one_ans[0] << "," << one_ans[1] << "," << one_ans[2] << endl;
//            cout << "换行" << endl;
//
//        }
//    }
//}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // 跳过重复元素，避免重复解
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({ nums[i], nums[left], nums[right] });

                    // **移动 left，避免重复**
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // **移动 right，避免重复**
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;

                    //这一里一定是要先去重，然后再left right 往后移动  一定要在纸上模拟一遍，如果不是100%的把握，肯定有测试用例会不通过！
                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ans;
    }
};



//int main() {
//    Solution s;
//
//    vector<vector<int>> ans;
//    vector<int> test = { -1,0,1,2,-1,-4 };
//    ans = s.threeSum(test);
//    cout << ans.size() << endl;
//
//
//}