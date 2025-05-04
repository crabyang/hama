#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> xi = { -1,0,1,0 };
    vector<int> yi = { 0,1,0,-1 };
    //方向向量
    void dfs_helper(vector<vector<char>>& grid, int x, int y) {
        int nx = grid.size();
        int ny = grid[0].size();
        for (int i = 0; i < 4; i++) {
            //四个方向
            grid[x][y] = '0';  //现在所在的状态是我们走入了这个‘1’，我们要把这个1变成0
            //后面是我们要找各个方向的1，然后把他变成0，这里要注意代码的顺序
            if (x + xi[i] >= 0 && x + xi[i] <= nx - 1 && y + yi[i] >= 0 && y + yi[i] <= ny - 1 && grid[x + xi[i]][y + yi[i]] == '1') {
                dfs_helper(grid, x + xi[i], y + yi[i]);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int nx = grid.size();
        if (nx == 0) {
            return 0;
        }
        int ny = grid[0].size();
        int ans = 0;
        for (size_t i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++) {
                if (grid[i][j] == '1') {
                    ans++;
                    dfs_helper(grid, i, j);  //把这个岛直接清零
                }
            }
        }
        return ans;

    }
};

