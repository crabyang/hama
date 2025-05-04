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
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 1);
        stack<int> s;

        for (int i = temperatures.size()-1; i >= 0; i--) {
            
            while (s.empty() != true && temperatures[s.top()] <= temperatures[i]) {  //����һ��Ҫע��Ⱥţ�
                s.pop();
            }


            if (s.empty() != true) {
                ans[i] = s.top() - i;
            }
            


            if (s.empty() == true) {
                ans[i] = 0;   //�����ջ��û���ҵ�ֵ����ʱջ�գ�ֱ�Ӹ���
            }
            s.push(i);  //���е�Ԫ�ض�����ջ��ͣ��
        }

        return ans;
    }
};

//int main() {
//    Solution s;
//    vector<int> temp = { 89,62,70,58,47,47,46,76,100,70 };
//
//    vector<int> ans = s.dailyTemperatures(temp);
//
//    for (int num : ans) {
//        cout << num << endl;
//
//    }
//}