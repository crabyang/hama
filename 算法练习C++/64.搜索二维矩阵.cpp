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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        //虽然是二维的，模拟是一维的就可以了
        int m = matrix.size();
        int n = matrix[0].size();



        int left = 0;
        int right = m * n - 1;

        //在进行查找的时候，把left，right映射到二维矩阵中去

        while (left <= right) {
            int left_map_x = left / n;
            int left_map_y = left % n;

            int right_map_x = right / n;
            int right_map_y = right % n;

            int mid = left + (right - left) / 2;

            int mid_map_x = mid / n;
            int mid_map_y = mid % n;

            if (matrix[mid_map_x][mid_map_y] == target) {
                return true;
            }
            else if (matrix[mid_map_x][mid_map_y] > target) {
                right = mid - 1;

            }
            else
            {
                left = mid + 1;

            }

        }

        return false;
    }
};