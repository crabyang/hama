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

	void midTravelse(TreeNode* curnode, vector<int>& ans) {
		if (curnode == nullptr) {
			return;
		}

		midTravelse(curnode->left, ans);
		ans.push_back(curnode->val);
		midTravelse(curnode->right, ans);
	}

	bool isValidBST(TreeNode* root) {
		vector<int> ans;
		midTravelse(root, ans);
		for (int i = 1; i < ans.size(); i++) {
			if (ans[i - 1] > ans[i]) {
				return true;
			}

		}

		return true;

	}
};