#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }
        if (n == 2) {
            return 2;
        }
        int dp1 = 1;  //dp[1] = 1;
        int dp2 = 2;  //dp[2] = 2;
        int dp3 = 3;
        for (int i = 3; i < n; i++) {  //我是从动态规划思路考虑过来的，dp1与dp2都是初始值，所以这里是从3开始的
            dp1 = dp2;
            dp2 = dp3;
            dp3 = dp1 + dp2;

        }
        return dp3;
    }
};

//int main() {
//    Solution s;
//    int ans = s.climbStairs(4);
//    cout << ans << endl;
//
//}