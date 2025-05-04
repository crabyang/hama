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

    int first = -1;
    int second = -1;

    vector<int> searchRange(vector<int>& nums, int target) {

        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;  //ÖØµã


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

        left = 0;
        right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                second = mid;
                left = mid + 1;


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


        return { first,second };
    }
};


//int main() {
//    vector<int> test = { 5,7,7,7,8,8,8,8,8,8,10 };
//    Solution s;
//    vector<int> ans = s.searchRange(test, 7);
//
//
//}