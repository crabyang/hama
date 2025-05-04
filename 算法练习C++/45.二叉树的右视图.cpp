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
	vector<int> rightSideView(TreeNode* root) {
		if (root == nullptr) {
			return {};
		}
		vector<int> ans;
		queue<TreeNode*> q;
		int cur_qSize;
		q.push(root);
		while (q.empty() != true) {
			cur_qSize = q.size();

			for (int i = 0; i < cur_qSize; i++) {
				//����ͬ�������
				TreeNode* curNode = q.front();
				q.pop();  //������ȡ�����Ժ�����ݵ���ȥ
				if (curNode->left != nullptr)
				{
					q.push(curNode->left);
				}
				if (curNode->right != nullptr) {
					q.push(curNode->right);
				}

				if (i == cur_qSize - 1) {
					ans.push_back(curNode->val);
				}
			}
			

		}

		return ans;
	}
};