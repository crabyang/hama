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
        for (int i = 3; i < n; i++) {  //���ǴӶ�̬�滮˼·���ǹ����ģ�dp1��dp2���ǳ�ʼֵ�����������Ǵ�3��ʼ��
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