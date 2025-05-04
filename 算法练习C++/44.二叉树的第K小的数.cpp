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
	int res, k;  //�������Ĳ��Ƿ�����ľֲ�����������һ�����еġ�ȫ�ֱ�����
	int kthSmallest(TreeNode* root, int k) {
		this->k = k;   //this��ʾ��ǰ����
		midTravelse(root);
		return res;

	}

	void midTravelse(TreeNode* curNode)
	{
		if (curNode == nullptr) {
			return;
		}

		midTravelse(curNode->left);
		//visit ��ǰ�ڵ㣡
		if (k == 0) return;//����Ѿ��鵽�ˣ�������Ĳ�ִ����
		if (--k == 0) res = curNode->val;
		midTravelse(curNode->right);

	}
};