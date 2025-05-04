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
            //����һ���µ����ݣ�����һֱҪ���ģ�û����������
            char c = s[right];
            right++;
            windows[c]++;

            while (windows[c] > 1) {
                //һֱ������������Ϊ�¼�����Ǹ���һ���ظ����ַ�
                //һֱ����Windows�����Ӧ���Ǹ��ظ�
                char d = s[left];
                left++;
                windows[d]--;

            }
            ans = max(ans, right - left);//ע��������ҿ��ģ�����˵ֱ���������+1
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

