#include "header.h"

/*

����һ�ö��������������ö���������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ���ָ��

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
	TreeNode * Convert(TreeNode *pRootOfTree)
	{
		if (!pRootOfTree) return nullptr;
		TreeNode *node = pRootOfTree;
		TreeNode *lastnode = nullptr;
		travIn(node, lastnode);
		while (node->left)
		{
			node = node->left;
		}
		return node;
	}
	void travIn(TreeNode *node, TreeNode *&lastnode)
	{
		if (!node) return;
		travIn(node->left, lastnode);
		node->left = lastnode;
		if (lastnode)
			lastnode->right = node;
		lastnode = node;
		travIn(node->right, lastnode);
	}
};
