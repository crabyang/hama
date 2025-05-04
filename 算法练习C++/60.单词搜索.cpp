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
    int target;
    vector<int> xi = { -1,0,1,0 };
    vector<int> yi = { 0,1,0,-1 };
    int nx;
    int ny;


    bool ans = false;   //在全局变量里设计答案，这样的话dfs函数直接设计为void就可以了，这样方便编程
    void dfs_help(vector<vector<char>>& board, string word,int curL, int x, int y,vector<vector<bool>> &visited) {

        if (word[curL] != board[x][y]) {
            return;
        }

        //if (visited[x][y] == true) {
        //    return;
        //}

        if (curL == target-1) {
            ans = true;
            return;

        }





        for (size_t i = 0; i < 4; i++)
        {

            if (x + xi[i] >= 0 && x + xi[i] < nx && y + yi[i] >= 0 && y + yi[i] < ny && visited[x + xi[i]][y + yi[i]] == false) {
                visited[x + xi[i]][y + yi[i]] = true;  //这才是真正要回溯的
                dfs_help(board, word, curL+1, x + xi[i], y + yi[i],visited);
                visited[x + xi[i]][y + yi[i]] = false;  //这才是真正要回溯的

            }
            //x = x + xi[i];
            //y = y + yi[i];
            //dfs_help(board, word, curL, x, y);   //这里直接写成dfs_help(board, word, curL, x + xi[i], y + yi[i])也是可以的
            //x = x - xi[i];
            //y = y - yi[i];
            //  这种是回溯的写法，其实也可以不这样写的，但其实代码是等效的

        }



    }
    bool exist(vector<vector<char>>& board, string word) {
        target = word.size();
        nx = board.size();
        ny = board[0].size();

        char begin = word[0];
        vector<pair<int, int>> beginLocation;

        vector<vector<bool>> visited(nx, vector<bool>(ny, false));




        for (int i = 0; i < nx; i++)
        {
            for (int j = 0; j < ny; j++) {
                if (board[i][j] == begin) {
                    beginLocation.push_back({ i,j });

                }
            }
        }

        for (auto pair : beginLocation) {
            if (ans == false) {
                visited[pair.first][pair.second] = true;  // 千万别忘了。。。。。
                dfs_help(board, word, 0, pair.first, pair.second,visited);
                //情况visited
                visited[pair.first][pair.second] = false;  // 千万别忘了。。。。。
            }
        }

        return ans;


    }
};

//int main() {
//    //vector<vector<char>> board = {{'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
//    vector<vector<char>> board = { {'a','a'} };
//    string word = "aaa";
//
//    Solution s;
//    bool ans1 = s.exist(board, word);
//
//
//    cout << ans1<<endl;
//
//}



/*
* helper函数不是void的方法：
* #include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int target;
    vector<int> xi = { -1, 0, 1, 0 };
    vector<int> yi = { 0, 1, 0, -1 };
    int nx;
    int ny;

    bool dfs_help(vector<vector<char>>& board, string& word, int curL, int x, int y, vector<vector<bool>>& visited) {
        if (curL == target) {
            return true;  // 找到完整的单词
        }

        if (x < 0 || x >= nx || y < 0 || y >= ny || visited[x][y] || board[x][y] != word[curL]) {
            return false;  // 越界或者字符不匹配或者已经访问过
        }

        visited[x][y] = true;  // 标记当前字符为访问过

        // 递归搜索四个方向
        for (size_t i = 0; i < 4; i++) {
            int newX = x + xi[i];
            int newY = y + yi[i];

            if (dfs_help(board, word, curL + 1, newX, newY, visited)) {    //这个if(递归){ true }的结构是关键
                return true;  // 如果找到，直接返回 true
            }
        }

        visited[x][y] = false;  // 回溯，取消访问标记
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        target = word.size();
        nx = board.size();
        ny = board[0].size();

        vector<vector<bool>> visited(nx, vector<bool>(ny, false));

        // 遍历所有位置，查找起始字符
        for (int i = 0; i < nx; i++) {
            for (int j = 0; j < ny; j++) {
                if (board[i][j] == word[0]) {  // 找到匹配的起始字符
                    if (dfs_help(board, word, 0, i, j, visited)) {
                        return true;  // 找到整个单词
                    }
                }
            }
        }

        return false;  // 没有找到
    }
};

* 
* 
*/