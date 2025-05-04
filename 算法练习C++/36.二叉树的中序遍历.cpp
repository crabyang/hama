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
	void helper(TreeNode* cur_node, vector<int> &res) {   //����һ��Ҫ������&
		//����һ���ݹ��������������Ҫ�Ѵ������Բ�������ʽ����ȥ
		if (cur_node == nullptr) {
			return;  //�������ˣ�
		}

		helper(cur_node->left, res);  //��ջ
		res.push_back(cur_node->val);  //��ջ��������б���
		helper(cur_node->right, res);  //��ջ


	}

	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> res;
		helper(root, res);
		return res;


	}
};