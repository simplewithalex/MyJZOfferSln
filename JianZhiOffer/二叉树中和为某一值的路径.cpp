#include "header.h"

/*

����һ�Ŷ������ĸ��ڵ��һ����������ӡ���������н��ֵ�ĺ�Ϊ��������������·����
·������Ϊ�����ĸ���㿪ʼ����һֱ��Ҷ����������Ľ���γ�һ��·����

*/


struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> res;
	vector<vector<int>> FindPath(TreeNode* root, int expectNumber)
	{
		if (root == nullptr)
			return {};
		vector<int> vec;
		dfs(root, expectNumber, 0, vec);
		return res;
	}
	void dfs(TreeNode *root, int number, int sum, vector<int> &vec)
	{
		vec.push_back(root->val);
		sum += root->val;
		if ((!root->left) && (!root->right))
		{
			if (sum == number)
			{
				res.push_back(vec);
				return;
			}
			else
				return;
		}
		if (root->left)
		{
			dfs(root->left, number, sum, vec);
			vec.pop_back();
		}
		if (root->right)
		{
			dfs(root->right, number, sum, vec);
			vec.pop_back();
		}
	}
};
