#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	TreeNode* Switch_helper(vector<int>& nums, int left, int right) {
		if (left<right) {
			return nullptr;
			//基本情况设计

		}

		int mid = (left + right) / 2;  //取中点,因为是向左取中点，所以说除非是一个节点的情况，mid一定是会大于right至少1的，因为是向左取中点的

		//子问题的结合方法是当前mid节点左右节点都是自身已经进行二叉排序树排列的
		TreeNode* curNode = new TreeNode(nums[mid]);
		curNode->left = Switch_helper(nums, left, mid - 1);
		curNode->right = Switch_helper(nums, mid + 1, right);

		return curNode;


	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode* root = Switch_helper(nums, 0, nums.size() - 1);
		return root;
	}
};