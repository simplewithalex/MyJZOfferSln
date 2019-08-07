#include "header.h"

/*

����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·����
�·���ĳ���Ϊ������ȡ�

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
	int TreeDepth(TreeNode *pRoot)
	{
		if (!pRoot) return 0;
		return 1 + max(TreeDepth(pRoot->left), TreeDepth(pRoot->right));
	}
};
