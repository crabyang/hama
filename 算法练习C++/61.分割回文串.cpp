#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <string>
using namespace std;


class Solution {
public:

    vector<vector<string>> ans;
    void dfs_helper(string s, int cur_index,vector<string> &container, vector<vector<bool>> &dp) {
        if (cur_index == s.size()) {
            ans.push_back(container);
            return;
        }


        for (int i = cur_index; i < s.size(); i++) {
            if (dp[cur_index][i] == true) {
                container.push_back(s.substr(cur_index, i-cur_index+1));
                dfs_helper(s, i + 1, container, dp);
                container.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int len = s.length();
        vector<vector<bool>> dp(len, vector<bool>(len,false));

        for ( int i = len-1; i >= 0 ; i--)
        {
            for (int j = 0; j < len; j++) {
                if (i >= j) {
                    dp[i][j] = true;
                }
                else
                {
                    if (dp[i + 1][j - 1] == true && s[i] == s[j]) {
                        dp[i][j] = true;
                    }
                }
            }
        }//构建dp表，方便记忆化查询


        vector<string> container;

        dfs_helper(s, 0, container, dp);


        return ans;
    }
};

//int main() {
//    Solution s;
//    string test = "aab";
//
//    vector<vector<string>> ans2 = s.partition(test);
//
//    int i;
//
//
//
//}