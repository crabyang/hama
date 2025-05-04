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

    int index = 0;  //����±���������еĺ���������ģ�����˵������Ϊһ��ȫ�ֱ���
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
            ans_cur = ans_cur + cur_s;      //������д��cur_s = cur_s + cur_s  �����Ļ��ᵼ�·���  1 2 4 8
        }
        return ans_cur;

    }
    string decodeString(string s) {
        //������ȫ���Լ�д�ģ�����ʱ�仭�˱Ƚϳ���ʱ�䰡
        //helper�������Ǵ��������⣬ÿһ��������ķ���ֵ����һ���ַ�������һ��Ҫע�Ᵽ��������ķ���ֵ��Ȼ��ƴ���������أ����ǹؼ�
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