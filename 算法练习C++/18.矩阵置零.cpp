#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();


        //因为第一行和第一列是要作为标记位的，我们首先要确定第一行和第一列本身初始的时候是不是有0的

        bool A = false;
        bool B = false;

        for (int i = 0; i < m; i++) {
            if (matrix[i][0] == 0) {
                A = true;
            }
        }

        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 0) {
                B = true;
            }
        }


        //开始搜索矩阵中的0

        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }

        }



        //操作赋0
        for (int i = 1; i < m; i++)   //这里一定要从1开始，第一行和第一列我们单独处理，现在完全只是当做标志位！
        {
            if (matrix[i][0] == 0) {
                for (int j = 1; j < n; j++)
                {
                    matrix[i][j] = 0;
                }
            }
        }



        for (int j = 1; j < n; j++)
        {
            if (matrix[0][j] == 0) {
                for (int i = 1; i < m; i++)
                {
                    matrix[i][j] = 0;
                }
            }
        }


        if (B == true) {
            for (int j = 0; j < n; j++)
            {
                matrix[0][j] = 0;
            }
        }

        if (A == true) {
            for (int i = 0; i < m; i++)
            {
                matrix[i][0] = 0;
            }
        }




    }
};

//int main() {
//    Solution s;
//    vector<vector<int>> test = { {1,1,1},{1,0,1},{1,1,1} };
//    s.setZeroes(test);
//
//}

