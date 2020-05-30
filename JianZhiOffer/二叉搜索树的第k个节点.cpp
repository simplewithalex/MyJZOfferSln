#include "header.h"

/*

����һ�ö��������������ҳ����еĵ�k���Ľ�㡣
����,(5��3��7��2��4��6��8)�У��������ֵ��С˳�����������ֵΪ4��

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
	TreeNode * KthNode(TreeNode *pRoot, int k)
	{
		int num = 0;
		return travIn(pRoot, num, k);
	}
	TreeNode * travIn(TreeNode *node, int &num, int k)
	{
		if (!node) return nullptr;
		TreeNode *temp;
		temp = travIn(node->left, num, k);
		if (temp)
			return temp;
		num += 1;
		if (num == k)
			return node;
		temp = travIn(node->right, num, k);
		if (temp)
			return temp;
		return nullptr;
	}
};
