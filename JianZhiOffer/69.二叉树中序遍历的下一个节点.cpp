#include "header.h"

/*

����һ�������������е�һ����㣬���ҳ��������˳�����һ����㲢�ҷ��ء�
ע�⣬���еĽ�㲻�����������ӽ�㣬ͬʱ����ָ�򸸽���ָ�롣

*/


struct TreeLinkNode {
	int val;
	struct TreeLinkNode *left;
	struct TreeLinkNode *right;
	struct TreeLinkNode *next;
	TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
	TreeLinkNode* GetNext(TreeLinkNode *pNode)
	{
		if (!pNode) return nullptr;
		if (pNode->right)
		{
			pNode = pNode->right;
			while (pNode->left)
				pNode = pNode->left;
		}
		else
		{
			while (pNode->next&&pNode == pNode->next->right)
				pNode = pNode->next;
			pNode = pNode->next;
		}
		return pNode;
	}
};