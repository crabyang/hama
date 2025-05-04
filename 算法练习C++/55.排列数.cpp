#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:



    void dfs(vector<vector<int>>& ans, vector<int>& nums, int level) {

        int length = nums.size();
        if (level == length) {
            ans.push_back(nums);
            return;
        }

        for (int i = level; i < length; i++)
        {
            swap(nums[level], nums[i]);
            dfs(ans, nums, level + 1);
            swap(nums[level], nums[i]);
            //���򴴽�һ����ʱ�ı������飬����һֱ������ԭ�ص�nums���޸Ĳ������
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs(ans, nums, 0);
        return ans;

    }
};

//int main() {
//    vector<int> test = { 1,2,3 };
//    vector<vector<int>> ans;
//    Solution s;
//    ans = s.permute(test);
//    for (vector<int> list : ans) {
//        for (int num : list) {
//
//        }
//    }
//
//}