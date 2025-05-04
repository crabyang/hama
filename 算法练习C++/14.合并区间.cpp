#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;


bool compare1(const vector<int>& a, const vector<int>& b) {
    return a[0] < b[0];
    //根据左值进行升序排序
}

class Solution {
public:


    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int ans_index = 0;   //当前答案的前端指针
        sort(intervals.begin(), intervals.end(),compare1);
        ans.push_back(intervals[0]);
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> cur_interval = intervals[i];
            if (ans[ans_index][1] >= cur_interval[0]) {
                ans[ans_index][1] = max(ans[ans_index][1], cur_interval[1]);  
                ans[ans_index][0] = min(ans[ans_index][0], cur_interval[0]);
            }
            else
            {
                //两个interval没有重合区间
                ans.push_back(cur_interval);
                ans_index++;
            }
        }

        return ans;

    }
};

//int main() {
//    Solution s;
//    //vector<vector<int>> test = { {1,3},{2,6},{8,10},{15,18} };
//    vector<vector<int>> test = { {1,4},{0,0} };
//    vector<vector<int>> ans = s.merge(test);
//
//    for (vector<int> interval : ans) {
//        cout << '[';
//        for (int i : interval) {
//            cout << i << ",";
//        }
//        cout << ']' << endl;
//
//    }
//}