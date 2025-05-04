#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> table;
        unordered_map<char, int> window;
        for (char c : p) {
            table[c]++;  //统计各字符标准数
        }
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            //装入当前的字符
            char c = s[right];
            if (table.find(c) == table.end()) {
                //如果遇到了完全不是的字符，直接全部跳过
                right++;
                left = right;
                for (auto &pair : window) {
                    pair.second = 0;
                    //记得要清空
                }
                continue;

            }
            window[c]++;
            right++;

            while (window[c] > table[c]) {  //注意这里一定是要>，因为可能这个字母不止一个，只有在超过的时候才是要截断的
                char d = s[left];
                window[d]--;
                left++;
            }

            if (right - left == p.size()) {
                //上一步window[c] > table[c]的限制，
                //会使得如果有一个字符数目不对，就会立即结束
                //所以说当驶出while判断，并且当前的字符数目还是正确的，
                //那么答案一定就是正确的，也就是说构成了充分条件
                ans.push_back(left);

            }
            

        }

        return ans;
    }
};

//int main() {
//    Solution s;
//    string test = "cbaebabacd";
//    string sub = "abc";
//    vector<int> ans = s.findAnagrams(test,sub);
//    for (int num : ans) {
//        cout << num << endl;
//    }
//
//
//}

