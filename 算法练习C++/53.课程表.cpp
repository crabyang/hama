#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> q;  //��¼���Ϊ0�Ľڵ�

        vector<int> inDegree(numCourses, 0);
        vector<vector<int>> graph(numCourses);

        for (vector<int> edge : prerequisites) {
            int u = edge[0];//ע���������
            int v = edge[1];

            graph[u].push_back(v);
            inDegree[v]++;  //ע�������

        }

        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        while (q.empty() != true) {
            int node = q.front();
            q.pop();
            for (int neib : graph[node]) {
                inDegree[neib]--;
                if (inDegree[neib] == 0) {
                    q.push(neib);
                }
            }
        }

        for (int de : inDegree) {
            if (de != 0) {
                return false;
            }

        }

        return true;


    }
};