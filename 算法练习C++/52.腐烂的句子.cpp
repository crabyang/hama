#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
   

    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0;
        vector<int> xi = { -1,0,1,0 };
        vector<int> yi = { 0,1,0,-1 };
        int nx = grid.size();
        int ny = grid[0].size();
        vector<pair<int, int>> fulan;
        queue<pair<int, int>> q;
        int time = 0;


        for (int i = 0; i < nx; i++) {
            for (int j = 0; j < ny; j++)
            {
                if (grid[i][j] == 1) {
                    fresh++;
                }
                if (grid[i][j] == 2) {
                    fulan.push_back({ i,j });
                    q.push({ i,j });
                }
            }
        }

        if (fresh == 0) {
            return 0;  //完全没有新鲜的橘子，不用花时间感染，直接报0  ————特殊情况
        }

        if (q.empty() == true) {
            return -1;       //没有腐败橘子，无法腐败  ————特殊情况
        }

        while (q.empty() != true) {
            int q_size = q.size();
            
            for (size_t i = 0; i < q_size; i++)
            {
                auto cur_fulan = q.front();
                int cur_x = cur_fulan.first;
                int cur_y = cur_fulan.second;


                q.pop();
                for (size_t j = 0; j < 4; j++)
                {
                    if (cur_x + xi[j] >= 0 && cur_x + xi[j] < nx &&
                        cur_y + yi[j] >= 0 && cur_y + yi[j] < ny) {
                        if (grid[cur_x + xi[j]][cur_y + yi[j]] == 1) 
                        {
                            grid[cur_x + xi[j]][cur_y + yi[j]] = 2;
                            fresh--;
                            q.push({ cur_x + xi[j] ,cur_y + yi[j] });

                        }
                    }
                }

            }
            //一次时间内的行为都结束了
            time++;
            if (fresh == 0) {
                return time;
            }
            if (q.empty() == true && fresh != 0) {
                return -1;
            }
       }

        return time;

    }
};

//int main() {
//    vector<vector<int>> grid = {  {2,1,1} ,{1,1,0},{0,1,1} };
//    Solution s;
//    int ans = s.orangesRotting(grid);
//    cout << ans << endl;
//
//}