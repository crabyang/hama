#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> location;
        size_t index = 0;
        for (auto& num : nums) {
            //location[num] = index;  //����Hash�ļ�ֵ��,ÿһ��Ҫ�Ȳ��ң�Ȼ���ٰ����ݷ��뵽Hash����
            
                if ((location.find(target - num) != location.end()) && location[target-num]!=index)
                {
                    //һ��װ��һ����ң�����Ҫȫ���������Ժ���ܲ��ң����������ж�̬��˼ά
                    int  ans2 = location[(target - num)];
                    vector<int> ans = {(int)index,ans2 };
                    return ans;
                }
                location[num] = (int)index;  //����Hash�ļ�ֵ��
                index++;   //ע��index++�Ĵ���λ�ã�Ҫ������ʹ���˵�ǰ��ȫ����index�����ȥ�����ǵ�ѭ�����������޸�
                
        }

        return {};



    }
};

//#ifdef Main1
//int main() {
//    Solution solution;
//    vector<int> nums = { 3,3 };
//    int target = 6;
//    vector<int> result = solution.twoSum(nums, target);
//    if (result.empty() == false) {
//        cout << "��Ϊ��" << target << "are:" << result[0] << "and" << result[1] << endl;
//
//    }
//    else
//    {
//        cout << "No solution found." << endl;
//
//
//    }
//
//    return 0;
//
//}
//#endif

