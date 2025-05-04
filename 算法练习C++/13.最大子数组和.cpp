#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int ans = INT16_MIN;
        int min_pre = 0;
        int presum = 0;
        for (int num : nums) {
            presum += num;
            ans = max(ans, presum - min_pre);//���maxֵһֱ�ڱ�����ʱ��ά���ŵ�
            min_pre = min(min_pre, presum);
        }
        return ans;
    

    }
};