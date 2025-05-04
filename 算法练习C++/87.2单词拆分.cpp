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
//        //������߼����ǣ������������һ���Ӵ������У���ô������Ӵ�֮ǰ��Ҳ�����У���ô���ǿ��Դճɵģ�Ȼ��һֱ������Ŀ�꣬��ô���ǿ��Դճɵ�
//        //  ����˵  abcdefg    ���ǲ��ҵ����Ӵ�efg�������ǵ�wordDict����"efg",�������Ƿ���������abcd�ǿ��Ա�worddict�ճ����ģ���ôabcdefg���ǿ��Ա��ճ�����
//
//
//        bool wordBreak(string s, vector<string>&wordDict) {
//            int n = s.length();
//
//            // DP���飬��ʼ��Ϊfalse��dp[0] = true��ʾ���ַ������Ա��ָ�
//            vector<bool> dp(n + 1, false);
//            dp[0] = true;
//
//            // ��wordDictת��Ϊunordered_set������ʱ����Ч
//            unordered_set<string> dict(wordDict.begin(), wordDict.end());
//
//            // ��̬�滮
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