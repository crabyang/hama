#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

//����Ĵ����ǵ�һ�棬������ʵ���˵ģ�����û��ʵ��ȥ�أ�ȥ����ʵ��������һ���ؼ���һ�����㣡
// 
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        unordered_map<int, vector<int>> map; //һ��ֵ�����еĶ�Ӧ���±��
//        vector<vector<int>> ans;
//        
//
//        for (int i = 0; i < nums.size(); i++) {
//            if (map.find(nums[i]) != map.end()) {
//                //����װ��
//                map[nums[i]].push_back(i);
//            }
//            else
//            {
//                //��ʼ��
//                vector<int> c = { i };
//                map[nums[i]] = c;
//            }
//        }
//
//
//        for (int i = 0; i < nums.size(); i++) {
//            for (int j = i + 1; j < nums.size(); j++) {
//                int complement = 0 - nums[i] - nums[j];  //�������еĶ�Ԫ��
//                if (map.find(complement)!=map.end()) {
//                    vector<int> list = map[complement];
//                    for (int num : list) {
//                        if (num != i && num != j  && j<num) {
//                            vector<int> one_ans = { nums[i],nums[j],nums[num] };
//                            ans.push_back(one_ans);
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//
//        return ans;
//    }
//};

//int main() {
//    Solution solution;
//    vector<int> test = { -1,0,1,2,-1,-4 };
//    vector<vector<int>> ans = solution.threeSum(test);
//    for (vector<int> one_ans : ans) {
//        for (int i = 0; i < 3; i++) {
//            cout << one_ans[0] << "," << one_ans[1] << "," << one_ans[2] << endl;
//            cout << "����" << endl;
//
//        }
//    }
//}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue; // �����ظ�Ԫ�أ������ظ���
            }
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    ans.push_back({ nums[i], nums[left], nums[right] });

                    // **�ƶ� left�������ظ�**
                    while (left < right && nums[left] == nums[left + 1]) left++;
                    // **�ƶ� right�������ظ�**
                    while (left < right && nums[right] == nums[right - 1]) right--;

                    left++;
                    right--;

                    //��һ��һ����Ҫ��ȥ�أ�Ȼ����left right �����ƶ�  һ��Ҫ��ֽ��ģ��һ�飬�������100%�İ��գ��϶��в��������᲻ͨ����
                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return ans;
    }
};



//int main() {
//    Solution s;
//
//    vector<vector<int>> ans;
//    vector<int> test = { -1,0,1,2,-1,-4 };
//    ans = s.threeSum(test);
//    cout << ans.size() << endl;
//
//
//}