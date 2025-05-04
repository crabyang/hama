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


    bool ans = false;   //��ȫ�ֱ�������ƴ𰸣������Ļ�dfs����ֱ�����Ϊvoid�Ϳ����ˣ�����������
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
                visited[x + xi[i]][y + yi[i]] = true;  //���������Ҫ���ݵ�
                dfs_help(board, word, curL+1, x + xi[i], y + yi[i],visited);
                visited[x + xi[i]][y + yi[i]] = false;  //���������Ҫ���ݵ�

            }
            //x = x + xi[i];
            //y = y + yi[i];
            //dfs_help(board, word, curL, x, y);   //����ֱ��д��dfs_help(board, word, curL, x + xi[i], y + yi[i])Ҳ�ǿ��Ե�
            //x = x - xi[i];
            //y = y - yi[i];
            //  �����ǻ��ݵ�д������ʵҲ���Բ�����д�ģ�����ʵ�����ǵ�Ч��

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
                visited[pair.first][pair.second] = true;  // ǧ������ˡ���������
                dfs_help(board, word, 0, pair.first, pair.second,visited);
                //���visited
                visited[pair.first][pair.second] = false;  // ǧ������ˡ���������
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
* helper��������void�ķ�����
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
            return true;  // �ҵ������ĵ���
        }

        if (x < 0 || x >= nx || y < 0 || y >= ny || visited[x][y] || board[x][y] != word[curL]) {
            return false;  // Խ������ַ���ƥ������Ѿ����ʹ�
        }

        visited[x][y] = true;  // ��ǵ�ǰ�ַ�Ϊ���ʹ�

        // �ݹ������ĸ�����
        for (size_t i = 0; i < 4; i++) {
            int newX = x + xi[i];
            int newY = y + yi[i];

            if (dfs_help(board, word, curL + 1, newX, newY, visited)) {    //���if(�ݹ�){ true }�Ľṹ�ǹؼ�
                return true;  // ����ҵ���ֱ�ӷ��� true
            }
        }

        visited[x][y] = false;  // ���ݣ�ȡ�����ʱ��
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        target = word.size();
        nx = board.size();
        ny = board[0].size();

        vector<vector<bool>> visited(nx, vector<bool>(ny, false));

        // ��������λ�ã�������ʼ�ַ�
        for (int i = 0; i < nx; i++) {
            for (int j = 0; j < ny; j++) {
                if (board[i][j] == word[0]) {  // �ҵ�ƥ�����ʼ�ַ�
                    if (dfs_help(board, word, 0, i, j, visited)) {
                        return true;  // �ҵ���������
                    }
                }
            }
        }

        return false;  // û���ҵ�
    }
};

* 
* 
*/