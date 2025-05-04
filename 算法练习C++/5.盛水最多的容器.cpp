#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;



class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_ans = 0;

        //初始化一下最大值
        max_ans = (height.size() - 1) * min(height[0], height[height.size() - 1]);


        while (left < right) {
            if (height[left] < height[right]) {
                //如果左边小，那么就从左边开始
                int cur_left_num = height[left];
                int cur_right_num = height[right];
                while (height[left] <= cur_left_num && left<right) {
                    left++;
                }
                //跳出while循环，说明找到一个跟高的柱子
                int cur_Area = (right - left) * min(height[left], height[right]);
                if (cur_Area > max_ans) {
                    max_ans = cur_Area;
                }
            }
            else
            {
                //如果右边小，那么就从右边开始
                int cur_left_num = height[left];
                int cur_right_num = height[right];
                while (height[right] <= cur_right_num && left < right) {
                    right--;
                }
                //跳出while循环，说明找到一个跟高的柱子
                int cur_Area = (right - left) * min(height[left], height[right]);
                if (cur_Area > max_ans) {
                    max_ans = cur_Area;
                }
            }
        }

        return max_ans;
    }
};

//int main(){
//    Solution s;
//    vector<int> test = { 1,8,6,2,5,4,8,3,7 };
//    int ans = s.maxArea(test);
//    cout << ans << "!!!" << endl;
//
//}