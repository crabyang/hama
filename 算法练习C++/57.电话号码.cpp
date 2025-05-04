#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <string>
using namespace std;


class Solution {
public:
    //返回值要是一个子问题
    vector<string> ans;
    unordered_map<char, vector<char>> table;

    void dfs_helper(string digits, string& container, int depth)
    {
        if (depth == digits.length()) {

            ans.push_back(container);

            return;
        }

        char cur_num = digits[depth];

        for (char c : table[cur_num]) {
            container = container + c;
            dfs_helper(digits, container, depth + 1);
            container.erase(depth, 1);

        }
    }


    vector<string> letterCombinations(string digits) {

        if (digits.length() == 0)
        {
            return {};   //特殊情况处理
        }

        table['2'] = { 'a','b','c' };
        table['3'] = { 'd','e','f' };
        table['4'] = { 'g','h','i' };
        table['5'] = { 'j','k','l' };
        table['6'] = { 'm','n','o' };
        table['7'] = { 'p','q','r','s'};
        table['8'] = { 't','u','v' };
        table['9'] = { 'w','x','y' ,'z'};

        string container = "";

        dfs_helper(digits, container, 0);

        return ans;

    }
};

//int main() {
//    Solution s;
//    string test = "23";
//    vector<string> ans2 = s.letterCombinations(test);
//
//    int end;
//
//
//}
