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


        //��Ϊ��һ�к͵�һ����Ҫ��Ϊ���λ�ģ���������Ҫȷ����һ�к͵�һ�б����ʼ��ʱ���ǲ�����0��

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


        //��ʼ���������е�0

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



        //������0
        for (int i = 1; i < m; i++)   //����һ��Ҫ��1��ʼ����һ�к͵�һ�����ǵ�������������ȫֻ�ǵ�����־λ��
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

