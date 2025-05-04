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

	int left_right_depth_helper(TreeNode* curnode, vector<int>& ans) {
		//如果要把每一次递归的中间结果记录下来，传入一个引用容器，否则中间过程是保存不下来的！
		if (curnode == nullptr) {
			return 0;//基本问题
		}

		int left = left_right_depth_helper(curnode->left, ans);
		int right = left_right_depth_helper(curnode->right, ans);//递归调用，合成子问题
		int cur_ans = max(left, right) + 1;  //一个节点的返回值，也就是子问题的解是他最长的那个左右孩子+1
		//之所以这样设计是为了可以递归的解决子问题


		if (curnode->left == nullptr && curnode->right == nullptr) {
			ans.push_back(left + right);  //但是在答案列表中存储的是这个节点的最大直径
		}

		if (curnode->left == nullptr || curnode->right == nullptr) {
			ans.push_back(left + right + 1);  //但是在答案列表中存储的是这个节点的最大直径
		}

		if (curnode->left != nullptr && curnode->right != nullptr) {
			ans.push_back(left + right + 2);  //但是在答案列表中存储的是这个节点的最大直径
		}




		if (curnode->left == nullptr && curnode->right == nullptr) {
			return 0;   //叶子节点不符合上面的计算法则，单独计算，返回0
		}
		else {
			return cur_ans;
		}



	}
	int diameterOfBinaryTree(TreeNode* root) {
		if (root->left == nullptr && root->right == nullptr) {
			return 0;
		}
		vector<int> ans;
		left_right_depth_helper(root, ans);
		int ans_diameter = *max_element(ans.begin(), ans.end());

		return ans_diameter;
	}
};