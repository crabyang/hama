#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:

    struct heapComparator
    {
        bool operator()(pair<int,int> p1, pair<int, int> p2) {
            return p1.second < p2.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>,heapComparator> heap;
        
        for (auto& pair : map) {
            heap.push({pair.first,pair.second  });

        }

        for (int i = 0; i < k; i++)
        {
            int curans = heap.top().first;
            heap.pop();
            ans.push_back(curans);
        }

        return ans;
    }
};


//int main() {
//    Solution s;
//    vector<int> test= { 1,1,1,32,3,2,31,3,21,312,3,123,13,2,2,3 };
//    vector<int> ans = s.topKFrequent(test,2);
//    for (int num : ans) {
//        cout << num << endl;
//
//    }
//}