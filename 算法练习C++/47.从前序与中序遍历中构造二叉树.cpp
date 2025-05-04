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


//class Solution {
//public:
//	//preorder的第一个节点，就是当前这个preorder列表表示的一棵树的根节点
////为了在inorder中快速定位根节点，使用一个Hash表,建立一个函数变量，不要是临时变量
//	unordered_map<int, int> rootMap;
//
//	
//	TreeNode* helper(vector<int>& cur_preorder, vector<int>& cur_inorder, int left_pre, int right_pre, int left_in, int right_in)
//	{
//		if (left_in > right_in) {
//			return nullptr;//基本情况
//		}
//		//返回值是已经经过处理了的树的根节点指针，是自底向上的
//
//		int curRoot = cur_preorder[left_pre];   //得到根节点的值
//		TreeNode* root = new TreeNode(curRoot);  //建立根节点
//
//		int root_index = rootMap[curRoot];  //这就是这个根节点在inorder的位子
//
//		//preorder的排序顺序是  [根，左子树，右子树]  我们要知道左子树有多少个节点，才能在preorder中定位左右子树的区间
//		int leftChildRootNum = root_index - left_in;
//		 
//
//		root->left = helper(cur_preorder, cur_inorder, left_pre+1, leftChildRootNum+left_pre,left_in,root_index-1);
//		root->right = helper(cur_preorder, cur_inorder, leftChildRootNum + left_pre+1, right_pre, root_index+1, right_in);
//		return root;   //返回值是每一个已经处理好的树的根节点，这就是子问题的结构
//	}
//
//	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
//		for (int i = 0; i < inorder.size(); i++) {
//			rootMap[inorder[i]] = i;
//
//		}
//
//		/*return helper(preorder, inorder, 0, inorder.size() - 1);*/
//
//
//
//	}
//};