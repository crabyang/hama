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
    //��������
    void dfs_helper(vector<vector<char>>& grid, int x, int y) {
        int nx = grid.size();
        int ny = grid[0].size();
        for (int i = 0; i < 4; i++) {
            //�ĸ�����
            grid[x][y] = '0';  //�������ڵ�״̬�����������������1��������Ҫ�����1���0
            //����������Ҫ�Ҹ��������1��Ȼ��������0������Ҫע������˳��
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
                    dfs_helper(grid, i, j);  //�������ֱ������
                }
            }
        }
        return ans;

    }
};

