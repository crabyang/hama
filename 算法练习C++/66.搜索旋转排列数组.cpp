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
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - right) / 2;
            //先判断那一边是有序的
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target <= nums[mid]) {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;

                }
              
            }
            else
            {
                if (nums[mid] <= target && target <= nums[nums.size() - 1])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;

                }
            }
        }

        return -1;
    }
};