#include "header.h"

/*

����������������������ϲ�����������ʹ�������еĽڵ���Ȼ�ǵ�������ġ�

ʾ��1��
���룺1->2->4, 1->3->4
�����1->1->2->3->4->4

���ƣ�0 <= ������ <= 1000

ע�⣺��������վ 21 ����ͬ��https://leetcode-cn.com/problems/merge-two-sorted-lists/

*/

//������
class Solution1 {
public:
	ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) 
	{
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode *dummy = new ListNode(-1);
		ListNode *pNode1 = l1;
		ListNode *pNode2 = l2;
		ListNode *pre = dummy;
		while (pNode1&&pNode2)
		{
			if (pNode1->val <= pNode2->val)
			{
				pre->next = pNode1;
				pNode1 = pNode1->next;
			}
			else
			{
				pre->next = pNode2;
				pNode2 = pNode2->next;
			}
			pre = pre->next;
		}
		if (pNode1) pre->next = pNode1;
		else pre->next = pNode2;
		pNode1 = dummy->next;
		delete dummy;
		return pNode1;
	}
};

//�ݹ鷽��
class Solution2 {
public:
	ListNode * mergeTwoLists(ListNode *l1, ListNode *l2)
	{
		if (!l1) return l2;
		else if (!l2) return l1;
		ListNode *pMergedHead = nullptr;
		if (l1->val <= l2->val)
		{
			pMergedHead = l1;
			pMergedHead->next = mergeTwoLists(l1->next, l2);
		}
		else
		{
			pMergedHead = l2;
			pMergedHead->next = mergeTwoLists(l1, l2->next);
		}
		return pMergedHead;
	}
};