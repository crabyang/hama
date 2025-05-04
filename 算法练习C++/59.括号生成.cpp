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
    vector<string> ans;
    vector<char> kuohao = { '(' , ')' };

    void dfs_helper(string container, int left, int right, int n) {
        if (left < right) {
            return;
        }
        if (left > n / 2 || right > n / 2) {
            return;  //�����ڽ�ռ����������֦���Ժ��֦
        }
        if (left == n / 2 && right == n / 2) {
            ans.push_back(container);
        }

        for (int i = 0; i < 2; i++) {
            container = container + kuohao[i];
            if (i == 0) {
                left++;
            }
            if (i == 1) {
                right++;
            }

            dfs_helper(container, left, right, n);

            //����
            container.erase(left + right - 1, 1);   //ɾ��ĩβ��Ԫ�أ�Ϊ�˻���,һ��Ҫ��ɾԪ�أ�Ȼ����left--��right--


            if (i == 0) {
                left--;
            }
            if (i == 1) {
                right--;
            }
            

        }

    }
    vector<string> generateParenthesis(int n) {
        string container = "";
        if (n == 0) {
            return {};

        }


        dfs_helper(container, 0, 0, n*2);
        return ans;



    }
};


//int main() {
//    Solution s;
//    
//
//    vector<string> ans = s.generateParenthesis(3);
//
//    cout << "jieshu" << endl;
//
//
//}