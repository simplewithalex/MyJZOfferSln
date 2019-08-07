#include "header.h"

/*

����һ����������ÿ���ڵ����нڵ�ֵ���Լ�����ָ�룬һ��ָ����һ���ڵ㣬��һ������ָ��ָ������һ���ڵ㣩��
���ؽ��Ϊ���ƺ��������head��

*/


struct RandomListNode {
	int label;
	struct RandomListNode *next, *random;
	RandomListNode(int x) :
		label(x), next(NULL), random(NULL) {}
};

class Solution {
public:
	RandomListNode * Clone(RandomListNode *pHead)
	{
		if (!pHead) return nullptr;
		RandomListNode *node = pHead;
		RandomListNode *newnode = nullptr;
		while (node)
		{
			newnode = new RandomListNode(node->label);
			newnode->next = node->next;
			node->next = newnode;
			node = newnode->next;
		}
		node = pHead;
		newnode = pHead->next;
		while (node)
		{
			if (node->random)
				newnode->random = node->random->next;
			node = node->next->next;
			if (newnode->next)
				newnode = newnode->next->next;
		}
		node = pHead;
		newnode = pHead->next;
		RandomListNode *pNewHead = newnode;
		while (node)
		{
			node->next = node->next->next;
			if (newnode->next)
				newnode->next = newnode->next->next;
			node = node->next;
			newnode = newnode->next;
		}
		return pNewHead;
	}
};