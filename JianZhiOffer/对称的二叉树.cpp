#include "header.h"

/*

��ʵ��һ�������������ж�һ�Ŷ������ǲ��ǶԳƵġ�
ע�⣬���һ��������ͬ�˶������ľ�����ͬ���ģ�������Ϊ�ԳƵġ�

*/

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
		val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
	bool isSymmetrical(TreeNode *pRoot)
	{
		if (!pRoot) return true;
		return trav(pRoot->left, pRoot->right);
	}
	bool trav(TreeNode *LNode, TreeNode *RNode)
	{
		if (!LNode || !RNode)
			return LNode == RNode;
		else if (LNode->val != RNode->val)
			return false;
		else
			return trav(LNode->left, RNode->right) && trav(LNode->right, RNode->left);
	}
};