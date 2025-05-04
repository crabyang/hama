#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <string>
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
	void helper(TreeNode* cur_node, vector<int> &res) {   //这里一定要用引用&
		//这是一个递归帮助函数，我们要把答案容器以参数的形式传进去
		if (cur_node == nullptr) {
			return;  //遇到空了，
		}

		helper(cur_node->left, res);  //入栈
		res.push_back(cur_node->val);  //出栈，计入答案列表中
		helper(cur_node->right, res);  //入栈


	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		helper(root, res);
		return res;


	}
};