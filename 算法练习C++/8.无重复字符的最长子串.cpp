#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> windows;
        int left = 0;
        int right = 0;
        int ans = 0;
        while (right < s.size()) {
            //读入一个新的数据，这是一直要做的，没有限制条件
            char c = s[right];
            right++;
            windows[c]++;

            while (windows[c] > 1) {
                //一直往里面所，因为新加入的那个是一个重复的字符
                //一直缩到Windows里面对应的那个重复
                char d = s[left];
                left++;
                windows[d]--;

            }
            ans = max(ans, right - left);//注意是左闭右开的，所以说直接相减不用+1
        }

        return ans;
    }
};

//int main() {
//    Solution s;
//    string test = "abcabcbb";
//    int ans = s.lengthOfLongestSubstring(test);
//    cout << ans << endl;
//
//}

