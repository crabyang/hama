#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i <= sqrt(n); i++) {
            squares.push_back(i * i);
        }

        vector<int> dp(n+1,INT16_MAX);
        dp[0] = 0;  //�����һ��Ҫ�ӵģ���Щ���պÿ���Ҫ���������
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for(int square:squares)
            {
                if (i >= square) {
                    dp[i] = min(dp[i], dp[i - square] + 1);
                }
                else
                {
                    break;  //û���˾������˳�
                }
            }
        }

        return dp[n];

    }
};

//int main() {
//    Solution s;
//    int ans = s.numSquares(13);
//    cout << ans;
//
//}