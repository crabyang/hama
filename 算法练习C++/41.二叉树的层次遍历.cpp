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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		queue<TreeNode*> q;

		q.push(root);
		while (q.empty() == false)
		{
			int curLevelSize = q.size();  //�����ֱ����ÿһ��ѭ����ʼ��ʱ����г�ʼ��
			vector<int> curList;
			for (int i = 0; i < curLevelSize; i++) {
				auto node = q.front();  //�õ����Ԫ�صĸ���
				q.pop();  //������Ԫ��
				curList.push_back(node->val);
				if (node->left != nullptr) {
					q.push(node->left); //ע����Ʋ���null
				}
				if (node->right != nullptr) {
					q.push(node->right);
				}
				
			}

			ans.push_back(curList);

		}

		return ans;
	}
};