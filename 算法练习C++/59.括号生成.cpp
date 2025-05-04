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
            return;  //都是在解空间树生成伸出枝了以后剪枝
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

            //回溯
            container.erase(left + right - 1, 1);   //删掉末尾的元素，为了回溯,一定要先删元素，然后再left--，right--


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