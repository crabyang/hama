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
    //���������Լ�д�Ĵ��룬д�ò���
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
    //                //���ﲻҪ������ƻ��ݣ�                       //���˵��һ����֧���ܼ���ִ����ȥ����Ӧ����ֱ��return 0������ֱ�Ӳ������������µݹ飡
    //                                                             //Ҳ���ǲ���ҪΪ����ƴ��롣ֻ�и��ϱ�׼�ģ�������ִ�У�����Ҫ��return True�ӵײ㴫������Ҳ����Ҫ�д��뼼�ɵģ�
    //                cur_index = origin_index;
    //                break;
    //            }
    //        }
    //        //�������forѭ����˵����ǰ��cur_s���е��ַ���ƥ���ˣ����Խ�����һ����
    //        //Ȼ������Ҫ���һ���߼�������һ����󷵻�true�ˣ�������еĴ𰸶�Ҫ����true����ʱ��Ϳ�����һ���ݹ�true����ƣ������
    //        if (dfs(s, wordDict, cur_index)) {
    //            return true;

    //        }

    //    }

    //    return false;


    //    
    //}
    bool dfs(string& s, vector<string>& wordDict, int cur_index) {
        // �����ǰ�����Ѿ������ַ���ĩβ��˵���ɹ��ָ�
        if (cur_index == s.length()) {
            return true;
        }

        // �����ֵ��е�ÿ������
        for (const string& word : wordDict) {
            // �����ǰ���ַ�����cur_index��ʼ�ܹ�ƥ���ֵ��е�ĳ������
            if (s.substr(cur_index, word.length()) == word) {
                // ���ƥ��ɹ����ݹ鴦���������
                if (dfs(s, wordDict, cur_index + word.length())) {
                    return true;  // һ���ҵ��ɹ�·�������̷���true
                }
            }
        }

        return false;  // ������е��ʶ�û�гɹ�ƥ�䣬����false
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