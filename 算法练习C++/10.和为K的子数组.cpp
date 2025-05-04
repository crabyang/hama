#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;



class Solution {
public:


    int subarraySum(vector<int>& nums, int k) {

        if (nums.size() == 1) {
            //这是方式在Hash表为0设计的错误
            if (nums[0] != k) {
                return 0;
            }
            else
            {
                return 1;
            }
        }
        vector<int> prefixNum(nums.size(), 0);
        prefixNum[0] = nums[0];
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            prefixNum[i] = prefixNum[i - 1] + nums[i];

        }
        
        unordered_map<int, int> table;
        table[0] = 1;  //前缀和为0的数目有1个,但是如果nums只有一个元素的话，这个会导致错误，所以说高位拦截
        for (int i = 0; i < prefixNum.size(); i++) {
            //一边装入一边计算
           
            int complement = prefixNum[i] - k;
            if (table.find(complement) != table.end()) {
                ans += table[complement];
            
            }
            table[prefixNum[i]]++;   //一定是先计算再放入的，否则会出错！
        }

        return ans;
    }
};


//int main() {
//    Solution s;
//    vector<int> test = { -1,-1,1 };
//    int k = 0;
//    int ans = s.subarraySum(test, k);
//    cout << ans << endl;
//
//
//}