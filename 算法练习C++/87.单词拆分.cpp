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
    //下面是我自己写的代码，写得不好
    //bool dfs(string s, vector<string>& wordDict, int cur_index) {
    //    if (cur_index == s.length()) {
    //        return true;
    //    }
    //    
    //    if (cur_index > s.length()) {
    //        return false;
    //    }
    //    int origin_index = cur_index;
    //    for (string cur_s : wordDict) {
    //        for (char c : cur_s) {
    //            if (c == s[cur_index]) {
    //                cur_index++;
    //            }
    //            else {
    //                //这里不要忘记设计回溯！                       //如果说有一个分支不能继续执行下去，不应该是直接return 0，而是直接不让他继续往下递归！
    //                                                             //也就是不需要为其设计代码。只有复合标准的，再往下执行，而且要把return True从底层传上来，也是需要有代码技巧的！
    //                cur_index = origin_index;
    //                break;
    //            }
    //        }
    //        //跳出这个for循环，说明当前的cur_s所有的字符都匹配了，可以进入下一层了
    //        //然后我们要设计一个逻辑，就是一旦最后返回true了，最后所有的答案都要返回true，这时候就可以用一个递归true的设计，来完成
    //        if (dfs(s, wordDict, cur_index)) {
    //            return true;

    //        }

    //    }

    //    return false;


    //    
    //}
    bool dfs(string& s, vector<string>& wordDict, int cur_index) {
        // 如果当前索引已经到达字符串末尾，说明成功分割
        if (cur_index == s.length()) {
            return true;
        }

        // 遍历字典中的每个单词
        for (const string& word : wordDict) {
            // 如果当前子字符串从cur_index开始能够匹配字典中的某个单词
            if (s.substr(cur_index, word.length()) == word) {
                // 如果匹配成功，递归处理后续部分
                if (dfs(s, wordDict, cur_index + word.length())) {
                    return true;  // 一旦找到成功路径，立刻返回true
                }
            }
        }

        return false;  // 如果所有单词都没有成功匹配，返回false
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        bool ans = dfs(s, wordDict, 0);
        return ans;
    }
};

//int main() {
//    Solution solution;
//    /*string s = "leetcode";
//    vector<string> wordDict = { "leet" , "code" };*/
//    string s = "applepenapple";
//    vector<string> wordDict = { "apple", "pen" };
//    bool ans = solution.wordBreak(s, wordDict);
//    cout << ans << endl;
//
//
//}