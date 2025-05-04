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
            table[c]++;  //ͳ�Ƹ��ַ���׼��
        }
        int left = 0;
        int right = 0;

        while (right < s.size()) {
            //װ�뵱ǰ���ַ�
            char c = s[right];
            if (table.find(c) == table.end()) {
                //�����������ȫ���ǵ��ַ���ֱ��ȫ������
                right++;
                left = right;
                for (auto &pair : window) {
                    pair.second = 0;
                    //�ǵ�Ҫ���
                }
                continue;

            }
            window[c]++;
            right++;

            while (window[c] > table[c]) {  //ע������һ����Ҫ>����Ϊ���������ĸ��ֹһ����ֻ���ڳ�����ʱ�����Ҫ�ضϵ�
                char d = s[left];
                window[d]--;
                left++;
            }

            if (right - left == p.size()) {
                //��һ��window[c] > table[c]�����ƣ�
                //��ʹ�������һ���ַ���Ŀ���ԣ��ͻ���������
                //����˵��ʻ��while�жϣ����ҵ�ǰ���ַ���Ŀ������ȷ�ģ�
                //��ô��һ��������ȷ�ģ�Ҳ����˵�����˳������
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

