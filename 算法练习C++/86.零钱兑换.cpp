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
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, INT_MAX));

        // 第一列填充0
        for (int j = 0; j < coins.size(); j++) {
            dp[j][0] = 0;
        }

        // 填充第一行
        for (int j = 1; j <= amount; j++) {
            if (j % coins[0] == 0) {
                dp[0][j] = j / coins[0];
            }
        }

        // 填充其他行
        for (int i = 1; i < coins.size(); i++) {
            for (int j = 1; j <= amount; j++) {
                // 不用当前硬币，继承上一行的结果
                dp[i][j] = dp[i - 1][j];

                // 用当前硬币
                if (j >= coins[i] && dp[i][j - coins[i]] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i]] + 1);
                }
            }
        }

        // 如果没有解，返回-1
        return dp[coins.size() - 1][amount] == INT_MAX ? -1 : dp[coins.size() - 1][amount];
    }
};

//int main() {
//    Solution s;
//    vector<int> coins = { 186, 419, 83, 408 };
//    int amount = 6249;
//    int ans = s.coinChange(coins, amount);
//    cout << ans << endl;
//    return 0;
//}
