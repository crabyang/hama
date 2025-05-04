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
		
		//����ֵ���Ѿ�ת�����������Ľڵ㣨�ݹ��ǻ���������еĽڵ�ģ�
		//�Ե�����ȥ������⣬ÿһ���ڵ㽻�������Һ��ӽڵ㣬�����Ѿ���������ǵ����Һ��ӽ�����
		TreeNode* left = swapChildHelper(curNode->left);
		TreeNode* right = swapChildHelper(curNode->right);
		TreeNode* temp;
		/*temp = left;
		left = right;
		right = temp;         //������û��ʵ�ʵ��޸ĵ�ǰcurNode�����ҽڵ�

		return curNode;*/
		
		curNode->right = left;
		curNode->left = right;

		return curNode;
	}

    TreeNode* invertTree(TreeNode* root) {
		
		return swapChildHelper(root);
    }
};