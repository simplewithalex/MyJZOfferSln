#include "header.h"

/*

��һ�����������а����������ҳ�������Ļ�����ڽ�㣬�������null��
*/


struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
		val(x), next(NULL) {}
};


class Solution {
public:
	ListNode * EntryNodeOfLoop(ListNode *pHead)
	{
		if (!pHead) return nullptr;
		ListNode *meetNode = haveCircle(pHead);
		if (!meetNode) return nullptr;
		ListNode *circleNode = pHead;
		while (circleNode != meetNode)
		{
			circleNode = circleNode->next;
			meetNode = meetNode->next;
		}
		return circleNode;
	}
	ListNode * haveCircle(ListNode *pHead)
	{
		ListNode *slow = pHead;
		ListNode *fast = pHead;
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (fast == slow)
				return fast;
		}
		return nullptr;
	}
};