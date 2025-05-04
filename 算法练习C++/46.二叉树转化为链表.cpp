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
				//���������ǿգ��������ǿ�
				curNode->right = left;
				curNode->left = nullptr;
			}
			else
			{
				if (curNode->left == nullptr && curNode->right != nullptr)
					{
						//�������ǿգ����������ǿ�
						curNode->right = right;
					}  
			}
		}

		



		//if (curNode->left == nullptr && curNode->right != nullptr)
		//{
		//	//�������ǿգ����������ǿ�
		//	curNode->right = right;
		//	//������뱾����߼�û�д�����Ϊʲô�������Ժ�������أ�����������û����else if�������߼��Ĵ������������룬���е�if�����Ƕ�ѡһ������˳��ִ�еģ�����
		// ִ��������ĸ�ֵ��������ξ�һ���ᱻִ���ˣ�����˵�������if  ��if-elseǶ�����кܴ������ģ�
		//}

		//�������ָ�붼Ϊ�գ�ֱ�ӷ����Լ��Ϳ�����
		return curNode;




	}

	void flatten(TreeNode* root) {
		helper(root);



	}
};