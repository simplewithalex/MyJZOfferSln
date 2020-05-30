#include "header.h"

/*

����һ������������, �ҵ�����������ָ���ڵ������������ȡ�

*/



struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
	{
		while (true)
		{
			if (root->val - p->val > 0 && root->val - q->val > 0)
				root = root->left;
			else if (root->val - p->val < 0 && root->val - q->val < 0)
				root = root->right;
			else
				break;
		}
		return root;
	}
};

/*

����һ��������, �ҵ�����������ָ���ڵ������������ȡ�

*/

class Solution2 {
public:
	TreeNode * lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
	{
		if (!root || root == p || root == q) return root;
		TreeNode *left = lowestCommonAncestor(root->left, p, q);
		TreeNode *right = lowestCommonAncestor(root->right, p, q);
		if (left || right)
		{
			if (left&&right)
				return root;
			else
				return left ? left : right;
		}
		else
		{
			return nullptr;
		}
	}
};