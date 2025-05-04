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
		//���Ҫ��ÿһ�εݹ���м�����¼����������һ�����������������м�����Ǳ��治�����ģ�
		if (curnode == nullptr) {
			return 0;//��������
		}

		int left = left_right_depth_helper(curnode->left, ans);
		int right = left_right_depth_helper(curnode->right, ans);//�ݹ���ã��ϳ�������
		int cur_ans = max(left, right) + 1;  //һ���ڵ�ķ���ֵ��Ҳ����������Ľ���������Ǹ����Һ���+1
		//֮�������������Ϊ�˿��Եݹ�Ľ��������


		if (curnode->left == nullptr && curnode->right == nullptr) {
			ans.push_back(left + right);  //�����ڴ��б��д洢��������ڵ�����ֱ��
		}

		if (curnode->left == nullptr || curnode->right == nullptr) {
			ans.push_back(left + right + 1);  //�����ڴ��б��д洢��������ڵ�����ֱ��
		}

		if (curnode->left != nullptr && curnode->right != nullptr) {
			ans.push_back(left + right + 2);  //�����ڴ��б��д洢��������ڵ�����ֱ��
		}




		if (curnode->left == nullptr && curnode->right == nullptr) {
			return 0;   //Ҷ�ӽڵ㲻��������ļ��㷨�򣬵������㣬����0
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