#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        stack<char> stk;

        //在去除一个右括号的时候，我们希望可以快速对照
        unordered_map<char, char> map;

        map['}'] = '{';
        map[']'] = '[';
        map[')'] = '(';

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                stk.push(c);

            }
            else
            {
                if (stk.empty()) {
                    //找到了右括号，但是此时栈中已经没有数值了
                    return false;
                }
                char cur = stk.top();
                stk.pop();
                if (map[c] != cur) {
                    return false;
                }

            }
        }

        //注意“（（（（”这一类的，不会报false,所以说要判断当前的栈是不是为空
        return stk.empty();

    }
};