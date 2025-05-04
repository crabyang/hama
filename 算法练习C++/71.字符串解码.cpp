#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:

    int index = 0;  //这个下标变量是所有的函数都共享的，所以说可以作为一个全局变脸
    string helper(string s,int num) {
        string cur_s = "";
        string cur_num = "";
        index++;
        for (; index < s.length(); index++)
        {
            if (s[index] == ']') {
                break;
            }
            if (s[index] == '[') {
                cur_s = cur_s + helper(s, stoi(cur_num));
                cur_num.clear();
            }

            if (s[index] >= 'a' && s[index] <= 'z') {
                cur_s = cur_s + s[index];
            }

            if (s[index] >= '0' && s[index] <= '9') {
                cur_num = cur_num + s[index];
            }

        }


        string ans_cur;
        for (size_t i = 0; i < num; i++)
        {
            ans_cur = ans_cur + cur_s;      //不可以写成cur_s = cur_s + cur_s  这样的话会导致翻倍  1 2 4 8
        }
        return ans_cur;

    }
    string decodeString(string s) {
        //代码完全是自己写的，但是时间画了比较长的时间啊
        //helper函数就是处理子问题，每一个子问题的返回值就是一个字符串，这一题要注意保存子问题的返回值，然后拼接起来返回，这是关键
        string ans = "";
        string cur_num = "";
        for (; index < s.length(); index++)
        {
            if (s[index] == '[') {

                ans = ans + helper(s, stoi(cur_num));
                cur_num.clear();
            }

            if (s[index] >= 'a' && s[index] <= 'z') {
                ans = ans + s[index];
            }

            if (s[index] >= '0' && s[index] <= '9') {
                cur_num = cur_num + s[index];
            }
        }

        return ans;

    }
};

//int main() {
//    Solution s;
//    string test = "4[2[jk]e1[f]]";
//    string ans = s.decodeString(test);
//    cout << ans << endl;
//
//}