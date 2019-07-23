#include "header.h"

/*

�������ö�����A��B���ж�B�ǲ���A���ӽṹ��
��ps������Լ��������������һ�������ӽṹ��

*/


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
	{
		if (!pRoot1 || !pRoot2) return false;
		bool res = false;
		if (pRoot1->val == pRoot2->val)
			res = trav(pRoot1, pRoot2);
		if (!res)
			res = HasSubtree(pRoot1->left, pRoot2);
		if (!res)
			res = HasSubtree(pRoot1->right, pRoot2);
		return res;
	}
	bool trav(TreeNode *node1, TreeNode *node2)
	{
		if (!node2) return true;
		if (!node1) return false;
		if (node1->val != node2->val)
			return false;
		else
			return trav(node1->left, node2->left) && trav(node1->right, node2->right);
	}
};