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
	int res, k;  //这个定义的不是方法里的局部变量，是在一个类中的“全局变量”
	int kthSmallest(TreeNode* root, int k) {
		this->k = k;   //this表示当前对象
		midTravelse(root);
		return res;

	}

	void midTravelse(TreeNode* curNode)
	{
		if (curNode == nullptr) {
			return;
		}

		midTravelse(curNode->left);
		//visit 当前节点！
		if (k == 0) return;//如果已经查到了，就下面的不执行了
		if (--k == 0) res = curNode->val;
		midTravelse(curNode->right);

	}
};