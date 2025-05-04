#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_set>
using namespace std;



class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;  //ά��һ����
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
                int start = num;  //�γ�һ������
                //�������else���飬˵����ǰ��һ������һ�����е�ͷ
                while (table.count(start + 1)) {
                    //��ʼ�������Ѱ��
                    cur_ans++;
                    start++;
                }
                //�������whileѭ���ˣ�˵�����ҵ�ͷ��
                ans = ans > cur_ans ? ans:cur_ans;
                //�ǵ�Ҫ���ѭ������
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