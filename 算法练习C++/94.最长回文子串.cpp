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
    string longestPalindrome(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        int nx = s.size();
        int ny = s.size();
        if (nx == 0) {
            return 0;
        }
        int ans = 1;
        pair<int, int> loca;


        for (int i = 0; i < nx; i++) {
            for (int j = 0; j < ny; j++)
            {
                if (i == j) {
                    dp[i][j] = 1;   //只有一个字符的肯定就是回文了
                }

                if (i > j) {
                    dp[i][j] = -1;

                }
            }
            
        }


        for (int i = nx-1; i >=0; i--)
        {
            for (int j = ny-1; j >= 0; j--)
            {
                if (i < j) {

                    if (dp[i + 1][j - 1] == -1) {
                        if (s[i] == s[j]) {
                            dp[i][j] = 2;
                            if (dp[i][j] > ans) {
                                ans = dp[i][j];
                                loca.first = i;
                                loca.second = j;
                            }
                        }
                        else
                        {
                            dp[i][j] = 0;
                        }

                    }
                    else if (dp[i + 1][j - 1] == 0) {
                        dp[i][j] = 0;
                    }
                    else {
                        //为一个实数
                        if (s[i] == s[j])
                        {
                            dp[i][j] = dp[i + 1][j - 1] + 2;
                            if (dp[i][j] > ans) {
                                ans = dp[i][j];
                                loca.first = i;
                                loca.second = j;
                            }

                        }
                        else
                        {
                            dp[i][j] = 0;
                        }
                    }




                }
            }
        }
        return s.substr(loca.first,loca.second-loca.first+1);

    }
};

//int main() {
//    Solution s;
//    string test = "babad";
//    string ans = s.longestPalindrome(test);
//    cout << ans << endl;
//
//}