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
	TreeNode* helper(TreeNode* curNode) {
		if (curNode == nullptr) {
			return nullptr;
		}

		TreeNode* left = helper(curNode->left);
		TreeNode* right = helper(curNode->right);

		if (curNode->left != nullptr && curNode->right != nullptr) {
			curNode->right = left;

			TreeNode* temp = curNode->right;
			while (temp->right != nullptr) {
				temp = temp->right;
			}

			temp->right = right;
			curNode->left = nullptr;
			temp->left = nullptr;

		}
		else
		{
			if (curNode->left != nullptr && curNode->right == nullptr)
			{
				//左子树不是空，右子树是空
				curNode->right = left;
				curNode->left = nullptr;
			}
			else
			{
				if (curNode->left == nullptr && curNode->right != nullptr)
					{
						//左子树是空，右子树不是空
						curNode->right = right;
					}  
			}
		}

		



		//if (curNode->left == nullptr && curNode->right != nullptr)
		//{
		//	//左子树是空，右子树不是空
		//	curNode->right = right;
		//	//这个代码本身的逻辑没有错！但是为什么加上了以后纠错了呢？————你没有用else if导致了逻辑的错误，你这样编码，所有的if并不是多选一，而是顺序执行的，导致
		// 执行了上面的赋值后，这个语句段就一定会被执行了，所以说连续多个if  和if-else嵌套是有很大的区别的！
		//}

		//如果两个指针都为空，直接返回自己就可以了
		return curNode;




	}

	void flatten(TreeNode* root) {
		helper(root);



	}
};