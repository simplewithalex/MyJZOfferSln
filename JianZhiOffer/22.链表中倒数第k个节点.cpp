#include "header.h"

/*

����һ����������������е�����k���ڵ㡣
Ϊ�˷��ϴ�����˵�ϰ�ߣ������1��ʼ�������������β�ڵ��ǵ�����1���ڵ㡣
���磬һ��������6���ڵ㣬��ͷ�ڵ㿪ʼ�����ǵ�ֵ������1��2��3��4��5��6���������ĵ�����3���ڵ���ֵΪ4�Ľڵ㡣

ʾ����
����һ������: 1->2->3->4->5, �� k = 2.
�������� 4->5.

*/

class Solution 
{
public:
	ListNode * getKthFromEnd(ListNode *head, int k) 
	{
		if (!head || k < 0) return nullptr;
		ListNode *ahead = head;
		while (k > 0)
		{
			if (!ahead) return nullptr;
			ahead = ahead->next;
			--k;
		}
		ListNode *behind = head;
		while (ahead)
		{
			ahead = ahead->next;
			behind = behind->next;
		}
		return behind;
	}
};