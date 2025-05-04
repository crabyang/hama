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
	TreeNode* Switch_helper(vector<int>& nums, int left, int right) {
		if (left<right) {
			return nullptr;
			//����������

		}

		int mid = (left + right) / 2;  //ȡ�е�,��Ϊ������ȡ�е㣬����˵������һ���ڵ�������midһ���ǻ����right����1�ģ���Ϊ������ȡ�е��

		//������Ľ�Ϸ����ǵ�ǰmid�ڵ����ҽڵ㶼�������Ѿ����ж������������е�
		TreeNode* curNode = new TreeNode(nums[mid]);
		curNode->left = Switch_helper(nums, left, mid - 1);
		curNode->right = Switch_helper(nums, mid + 1, right);

		return curNode;


	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		TreeNode* root = Switch_helper(nums, 0, nums.size() - 1);
		return root;
	}
};