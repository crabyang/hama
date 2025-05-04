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
	int helper(TreeNode* cur_node) {
		if (cur_node == nullptr) {
			return 0;
		}
		
		//�ݹ������ջȥ��⣨���Ǽ��㱾�ʣ�
		//�ݹ�������������������ȥ��⣨�����߼����ʣ�
		int leftDepth = helper(cur_node->left);
		int rightDepth = helper(cur_node->right);

		return max(leftDepth, rightDepth) + 1;



	}

	int maxDepth(TreeNode* root) {
		int ans = 0;
		ans = helper(root);
		return ans;
	}
};