#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 1);
        for (int i = 1; i <= nums.size(); i++) {
            for (int j = 1; j < i; j++) {
                if (nums[i-1] > nums[j-1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());

    }
};


//int main() {
//    Solution s;
//    vector<int> nums = { 1,3,6,7,9,4,10,5,6 };
//
//    int ans = s.lengthOfLIS(nums);
//    cout << ans << endl;
//
//}