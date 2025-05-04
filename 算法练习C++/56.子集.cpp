#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;



class Solution {
public:

    vector<int> curans;


    void dfs_subset(vector<vector<int>>& ans, vector<int>& nums, int depth) {
        if (depth == nums.size()) {
            ans.push_back(curans);
            return;
        }

        curans.push_back(nums[depth]);
        dfs_subset(ans, nums, depth + 1);
        curans.pop_back();
        dfs_subset(ans, nums, depth + 1);

    }

        
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        dfs_subset(ans, nums, 0);
        return ans;


    }
};