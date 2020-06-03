#include "header.h"

/*

����һ�������ͷ�ڵ㣬��β��ͷ����������ÿ���ڵ��ֵ�������鷵�أ���

ʾ�� 1��
���룺head = [1,3,2]
�����[2,3,1]

���ƣ�0 <= ������ <= 10000

*/

class Solution1 {
public:
	vector<int> reversePrint(ListNode *head) 
	{
		if (!head) return {};
		vector<int> res;
		stack<int> s;
		ListNode *node = head;
		while (node)
		{
			s.push(node->val);
			node = node->next;
		}
		while (!s.empty())
		{
			res.push_back(s.top());
			s.pop();
		}
		return res;
	}
};

class Solution2 {
public:
	vector<int> reversePrint(ListNode *head) 
	{
		vector<int> res;
		helper(head, res);
		return res;
	}
	void helper(ListNode *node,vector<int> &res)
	{
		if (!node) return;
		helper(node->next, res);
		res.push_back(node->val);
	}
};