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
            //���Ƿ�ʽ��Hash��Ϊ0��ƵĴ���
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
        table[0] = 1;  //ǰ׺��Ϊ0����Ŀ��1��,�������numsֻ��һ��Ԫ�صĻ�������ᵼ�´�������˵��λ����
        for (int i = 0; i < prefixNum.size(); i++) {
            //һ��װ��һ�߼���
           
            int complement = prefixNum[i] - k;
            if (table.find(complement) != table.end()) {
                ans += table[complement];
            
            }
            table[prefixNum[i]]++;   //һ�����ȼ����ٷ���ģ���������
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