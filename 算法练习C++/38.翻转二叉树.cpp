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
	TreeNode* swapChildHelper(TreeNode* curNode) {
		if (curNode == nullptr) {
			return nullptr;
		}
		
		//返回值是已经转化了左右树的节点（递归是会遍历到所有的节点的）
		//自底向上去解决问题，每一个节点交换的左右孩子节点，都是已经完成了他们的左右孩子交换的
		TreeNode* left = swapChildHelper(curNode->left);
		TreeNode* right = swapChildHelper(curNode->right);
		TreeNode* temp;
		/*temp = left;
		left = right;
		right = temp;         //这样并没有实际的修改当前curNode的左右节点

		return curNode;*/
		
		curNode->right = left;
		curNode->left = right;

		return curNode;
	}

    TreeNode* invertTree(TreeNode* root) {
		
		return swapChildHelper(root);
    }
};