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
//	//preorder�ĵ�һ���ڵ㣬���ǵ�ǰ���preorder�б��ʾ��һ�����ĸ��ڵ�
////Ϊ����inorder�п��ٶ�λ���ڵ㣬ʹ��һ��Hash��,����һ��������������Ҫ����ʱ����
//	unordered_map<int, int> rootMap;
//
//	
//	TreeNode* helper(vector<int>& cur_preorder, vector<int>& cur_inorder, int left_pre, int right_pre, int left_in, int right_in)
//	{
//		if (left_in > right_in) {
//			return nullptr;//�������
//		}
//		//����ֵ���Ѿ����������˵����ĸ��ڵ�ָ�룬���Ե����ϵ�
//
//		int curRoot = cur_preorder[left_pre];   //�õ����ڵ��ֵ
//		TreeNode* root = new TreeNode(curRoot);  //�������ڵ�
//
//		int root_index = rootMap[curRoot];  //�����������ڵ���inorder��λ��
//
//		//preorder������˳����  [������������������]  ����Ҫ֪���������ж��ٸ��ڵ㣬������preorder�ж�λ��������������
//		int leftChildRootNum = root_index - left_in;
//		 
//
//		root->left = helper(cur_preorder, cur_inorder, left_pre+1, leftChildRootNum+left_pre,left_in,root_index-1);
//		root->right = helper(cur_preorder, cur_inorder, leftChildRootNum + left_pre+1, right_pre, root_index+1, right_in);
//		return root;   //����ֵ��ÿһ���Ѿ�����õ����ĸ��ڵ㣬�����������Ľṹ
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