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
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (root == nullptr) {
			return nullptr;
		}

		if (root == p) {
			return root;
		}

		if (root == q) {
			return root;
		}


		TreeNode* left = lowestCommonAncestor(root->left, p, q);   //左孩子路径
		TreeNode* right = lowestCommonAncestor(root->right, p, q);   //右孩子路径
		if (left == nullptr && right == nullptr) {
			return nullptr;   //返回值，如果是左孩子路径和右孩子路径都为空，那么就代表没有公共节点，返回空
		}

		if (left != nullptr && right != nullptr) {
			return root;   //两条路径交汇，返回自身，自身就是答案   
		}

		if (left != nullptr && right == nullptr) {
			return left;   
		}


		if (left == nullptr && right != nullptr) {
			return right;   
		}
	}
};