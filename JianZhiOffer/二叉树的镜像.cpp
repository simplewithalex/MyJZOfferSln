#include "header.h"

/*

�������ľ���

���������Ķ�����������任ΪԴ�������ľ���

����:

Դ������
    8
   / \
  6   10
 / \  / \
5  7 9  11

�����

���������

    8
   /  \
  10   6
 / \  / \
11  9 7  5

*/




class Solution 
{
public:
	void Mirror(TreeNode *pRoot)
	{
		if (!pRoot) return;
		swap(pRoot->left, pRoot->right);
		Mirror(pRoot->left);
		Mirror(pRoot->right);
	}
};

