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

        //��ȥ��һ�������ŵ�ʱ������ϣ�����Կ��ٶ���
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
                    //�ҵ��������ţ����Ǵ�ʱջ���Ѿ�û����ֵ��
                    return false;
                }
                char cur = stk.top();
                stk.pop();
                if (map[c] != cur) {
                    return false;
                }

            }
        }

        //ע�⡰������������һ��ģ����ᱨfalse,����˵Ҫ�жϵ�ǰ��ջ�ǲ���Ϊ��
        return stk.empty();

    }
};