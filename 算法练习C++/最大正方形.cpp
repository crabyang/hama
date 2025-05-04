
#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:

    int find(vector<vector<int>>& presum, int x, int y, int a, int b) {
        return presum[a + 1][b + 1] - presum[x][b + 1] - presum[a + 1][y] + presum[x][y];

    }


    int maximalSquare(vector<vector<char>>& matrix) {
        int a = matrix.size();
        int b = matrix[0].size();

        vector<vector<int>> presum(a + 1, vector<int>(b + 1, 0));


        for (int i = 0; i < a; i++) {
            for (int j = 0; j < b; j++) {
                if (matrix[i][j] == '0') {
                    matrix[i][j] = 0;
                }
                else {
                    matrix[i][j] = 1;
                }
            }
        }


        for (int i = 1; i < a+1; i++) {
            for (int j = 1; j < b+1; j++) {
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + matrix[i-1][j-1];
            }

        }




        //nÆ½·½

        int minb = min(a, b);
        int curans = 0;
        for (int i = 1; i <= minb; i++) {
            for (int x = 0; x < a - i; x++) {
                for (int y = 0; y < b - i; y++) {
                    if (find(presum, x, y, x + i - 1, y + i - 1) == i * i) {
                        curans = max(i * i, curans);
                    }
                }
            }
        }


        return curans;








    }
};


int main() {
    Solution s;
    //vector<vector<char>> matrix = {
    //{'1','0','1','0','0'},
    //{'1','0','1','1','1'},
    //{'1','1','1','1','1'},
    //{'1','0','0','1','0'}
    //};


    vector<vector<char>> matrix =
    {
        {'1','0'},{'0','1'}
    };
    int ans = s.maximalSquare(matrix);

    cout << ans;


}