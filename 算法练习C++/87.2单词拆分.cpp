#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>
#include <algorithm>
//using namespace std;
//
//class Solution {
//public:
//    bool wordBreak(string s, vector<string>& wordDict) {
//        //总体的逻辑就是，我们如果看到一个子串可以有，那么在这个子串之前的也可以有，那么就是可以凑成的，然后一直到最后的目标，那么就是可以凑成的
//        //  比如说  abcdefg    我们查找到了子串efg，在我们的wordDict中有"efg",而且我们发现子问题abcd是可以被worddict凑出来的，那么abcdefg就是可以被凑出来的
//
//
//        bool wordBreak(string s, vector<string>&wordDict) {
//            int n = s.length();
//
//            // DP数组，初始化为false，dp[0] = true表示空字符串可以被分割
//            vector<bool> dp(n + 1, false);
//            dp[0] = true;
//
//            // 将wordDict转换为unordered_set，查找时更高效
//            unordered_set<string> dict(wordDict.begin(), wordDict.end());
//
//            // 动态规划
//            for (int i = 0; i < n; ++i) {
//                for (int j = i + 1; j <= n; ++j) {
//                    if (dp[i] && dict.count(s.substr(i, j - i))) {
//                        dp[j] = true;
//                    }
//                }
//            }
//
//            return dp[n];
//    }
//};