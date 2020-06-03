#include "header.h"

/*

����һ����������������е�����k����㡣

*/

class Solution {
public:
	ListNode * FindKthToTail(ListNode *pListHead, unsigned int k)
	{
		if (!pListHead || k<0) return nullptr;
		ListNode *ahead = pListHead;
		while (k > 0)
		{
			if (!ahead) return nullptr;
			ahead = ahead->next;
			--k;
		}
		ListNode *behind = pListHead;
		while (ahead)
		{
			behind = behind->next;
			ahead = ahead->next;
		}
		return behind;
	}
};