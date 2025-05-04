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


		TreeNode* left = lowestCommonAncestor(root->left, p, q);   //����·��
		TreeNode* right = lowestCommonAncestor(root->right, p, q);   //�Һ���·��
		if (left == nullptr && right == nullptr) {
			return nullptr;   //����ֵ�����������·�����Һ���·����Ϊ�գ���ô�ʹ���û�й����ڵ㣬���ؿ�
		}

		if (left != nullptr && right != nullptr) {
			return root;   //����·�����㣬��������������Ǵ�   
		}

		if (left != nullptr && right == nullptr) {
			return left;   
		}


		if (left == nullptr && right != nullptr) {
			return right;   
		}
	}
};