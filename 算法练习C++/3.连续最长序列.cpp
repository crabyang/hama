#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>
using namespace std;



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;  //维护一个答案
        unordered_set<int> table;
        for (int i = 0; i < nums.size();i++) {
            table.insert(nums[i]);
        }
        int cur_ans = 1;
        for (const int& num : table) {
            if(table.count(num-1)){
                continue;
            }
            else
            {
                int start = num;  //形成一个副本
                //来到这个else区块，说明当前的一个数是一个序列的头
                while (table.count(start + 1)) {
                    //开始连续向后寻找
                    cur_ans++;
                    start++;
                }
                //跳出这个while循环了，说明查找到头了
                ans = ans > cur_ans ? ans:cur_ans;
                //记得要清空循环变量
                cur_ans = 1;
            }
        }

        return ans;

    }
};


//int main() {
//    Solution solution;
//    vector<int> test = { 0,3,7,2,5,8,4,6,0,1 };
//    int ans = solution.longestConsecutive(test);
//    cout << ans << "!!!" << endl;
//}