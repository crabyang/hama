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
    vector<vector<int>> ans;

    //void dfs_helper(vector<int>& candidates, int curNum,vector<int> container) {


    //    //这里的candidates已经清洗过了
    //    for (int i = 0; i < candidates.size(); i++) {
    //        //if (candidates[i] > curNum) {
    //        //    return;  //剪枝     //return 会使得整个循环结束，但是是要遍历完的，所以说这里就是大于的时候不执行任何操作就可以了
    //        //}
    //        
    //        if (candidates[i] == curNum) {
    //            container.push_back(candidates[i]);  //这时候就可以直接转入
    //            ans.push_back(container);  //转入答案
    //            container.pop_back();  //也相当于是回溯了
    //        }

    //        if (candidates[i] < curNum) {
    //            container.push_back(candidates[i]);
    //            dfs_helper(candidates, curNum-candidates[i], container);
    //            container.pop_back();
    //        }
    //    }
    //}


    void dfs_helper(vector<int>& candidates, int curNum, vector<int> container, int index) {
        if (curNum == 0) {
            ans.push_back(container);
            return;
        }

        if (curNum < 0) {
            return;
        }

        //这里的candidates已经清洗过了
        for (int i = index; i < candidates.size(); i++) {
               container.push_back(candidates[i]);
               dfs_helper(candidates, curNum - candidates[i], container, i);
               container.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        //先去除candidates中大于与等于target的数，因为candidates是没有负数的，大于等于就直接有答案了
        
        for (size_t i = candidates.size()-1; i >0 ; i--)   //注意这里因为要删除数据，所以说是反向遍历
        {
            if (candidates[i] == target)
            {
                ans.push_back({ target });
                candidates.erase(candidates.begin()+i);
                continue;  //使用continue来控制循环，当前这个代码块执行了，后面的都直接跳过了
            }

            if (candidates[i] > target) {
                candidates.erase(candidates.begin() + i);
            }
        }

        sort(candidates.begin(), candidates.end());
        //要排序


        vector<int> container;

        dfs_helper(candidates, target, container,0);
        return ans;


    }
};

//int main() {
//    Solution s;
//    vector<int> test = { 2,9,3,6,7,8};
//
//
//    vector<vector<int>> ans = s.combinationSum(test, 7);
//
//    cout << "jieshu";
//
//
//}