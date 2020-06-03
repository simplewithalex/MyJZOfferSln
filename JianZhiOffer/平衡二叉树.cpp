#include "header.h"

/*

����һ�ö��������жϸö������Ƿ���ƽ���������
(�������������������1)

*/

class Solution {
public:
	bool IsBalanced_Solution(TreeNode *pRoot)
	{
		if (!pRoot) return true;
		return travpost(pRoot) == -1 ? false : true;
	}
	int travpost(TreeNode *pNode)
	{
		if (!pNode) return 0;
		int l = 0, r = 0;
		l = travpost(pNode->left);
		if (l == -1)
			return -1;
		r = travpost(pNode->right);
		if (r == -1)
			return -1;
		if (abs(l - r) > 1)
			return -1;
		else
			return 1 + max(l, r);
	}
};