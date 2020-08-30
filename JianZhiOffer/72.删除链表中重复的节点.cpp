#include "header.h"

/*

��һ������������У������ظ��Ľ�㣬��ɾ�����������ظ��Ľ�㣬�ظ��Ľ�㲻��������������ͷָ�롣 
���磬����1->2->3->3->4->4->5 �����Ϊ 1->2->5

*/

class Solution {
public:
	ListNode * deleteDuplication(ListNode *head)
	{
		if (!head) return nullptr;
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *pre = dummy;
		ListNode *cur = head;
		while (cur&&cur->next)
		{
			if (cur->next->val == cur->val)
			{
				deleteNode(pre, cur->val);
				cur = pre->next;
			}
			else
			{
				pre = cur;
				cur = cur->next;
			}
		}
		ListNode *pHead = dummy->next;
		delete dummy;
		return pHead;
	}
	void deleteNode(ListNode *node, int val)
	{
		while (node->next)
		{
			if (node->next->val == val)
			{
				ListNode *temp = node->next;
				node->next = temp->next;
				delete temp;
			}
			else
				break;
		}
	}
};