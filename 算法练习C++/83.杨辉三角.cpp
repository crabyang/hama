#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for (size_t i = 1; i <= numRows; i++)
        {
            vector<int> cur(i, 0);
            cur[0] = 1; //初始化杨辉三角的两边
            cur[i - 1] = 1;
            ans.push_back(cur);
        }

        for (int i = 2; i < numRows; i++) {
            for (int j = 1; j < i; j++) {
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }
        }

        return ans;
    }
};

//int main() {
//    Solution s;
//    vector<vector<int>> ans = s.generate(10);
//    for (vector<int> list : ans) {
//        cout << '[';
//        for (int num : list) {
//            cout << num << ',';
//
//        }
//        cout << ']' << endl;
//
//    }
//
//}