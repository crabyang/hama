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
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return  mid;

            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return left;
    }
};