#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return QuickSort2(nums, 0, nums.size() - 1, k);
    }

    int QuickSort2(vector<int> &nums, int low, int right, int k) {
        int i = low;
        int j = right;  //定义两个指针
        int pivot = nums[low];

        while (i != j) {
            while (i < j && nums[j] >= pivot) {
                j--;
            }
            while (i < j && nums[i] <= pivot) {
                i++;
            }

            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }

        swap(nums[low], nums[i]);
        if (i == nums.size() - k) {
            return nums[i];
        }

        if (i < nums.size() - k) {
            //i是当前找到的值，这样说明找小了，需要往上游去找！
            return QuickSort2(nums, i + 1, right, k); //这里记得要写return，一定是往下深入去找

        }
        else {
            return QuickSort2(nums, low, i - 1, k);
        }
    }
};

//int main() {
//    vector<int> arr = { 10, 7, 8, 9, 1, 5 };
//    int n = arr.size();
//
//    Solution s;
//    int ans = s.findKthLargest(arr, 2);
//
//    cout << ans << endl;
//
//    return 0;
//}