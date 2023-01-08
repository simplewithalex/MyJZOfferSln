#include "header.h"

/*

��ָ Offer II 077. ��������

���������ͷ��� head���뽫�䰴�������в���������������

ʾ�� 1��
���룺head = [4,2,1,3]
�����[1,2,3,4]

ʾ�� 2��
���룺head = [-1,5,3,4,0]
�����[-1,0,3,4,5]

ʾ�� 3��
���룺head = []
�����[]

��ʾ��
�����нڵ����Ŀ�ڷ�Χ [0, 5 * 10^4] ��
-10^5 <= Node.val <= 10^5

���ף�������� O(n log n) ʱ�临�ӶȺͳ������ռ临�Ӷ��£����������������

ע�⣺��������վ 148 ����ͬ��https://leetcode-cn.com/problems/sort-list/

*/

// �ݹ鷨�鲢
class Solution1 {
public:
	ListNode *sortList(ListNode *head) {
		if (!head || !head->next) return head;
		ListNode *pre = nullptr, *slow = head, *fast = head;
		while (fast && fast->next) {
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = nullptr;
		ListNode *l = nullptr, *r = nullptr;
		l = sortList(head);
		r = sortList(slow);
		return merge(l, r);
	}

private:
	ListNode *merge(ListNode *l, ListNode *r) {
		ListNode *dummy = new ListNode(-1);
		ListNode *temp = dummy;
		while (l && r) {
			if (l->val <= r->val) {
				temp->next = l;
				temp = temp->next;
				l = l->next;
			} else {
				temp->next = r;
				temp = temp->next;
				r = r->next;
			}
		}
		temp->next = l ? l : r;
		temp = dummy->next;
		delete dummy;
		dummy = nullptr;
		return temp;
	}
};

// �Ե׶��Ϲ鲢
class Solution2 {
public:
	ListNode *sortList(ListNode *head) {
		if (!head || !head->next) return head;
		ListNode *dummy = new ListNode(-1);
		dummy->next = head;
		ListNode *temp = head;
		int length = 0;
		while (temp) {
			++length;
			temp = temp->next;
		}
		for (int size = 1; size < length; size <<= 1) {
			ListNode *cur = dummy->next, *left = nullptr, *right = nullptr;
			ListNode *tail = dummy;
			while (cur) {
				left = cur;
				right = cut(left, size);
				cur = cut(right, size);
				tail->next = merge(left, right);
				while (tail->next) tail = tail->next;
			}
		}
		temp = dummy->next;
		delete dummy;
		dummy = nullptr;
		return temp;
	}

private:
	ListNode *cut(ListNode *head, int n) {
		ListNode *p = head;
		while (p && --n) p = p->next;
		if (!p) return nullptr;
		ListNode *post = p->next;
		p->next = nullptr;
		return post;
	}

	ListNode *merge(ListNode *l, ListNode *r) {
		ListNode *dummy = new ListNode(-1);
		ListNode *temp = dummy;
		while (l && r) {
			if (l->val <= r->val) {
				temp->next = l;
				temp = temp->next;
				l = l->next;
			} else {
				temp->next = r;
				temp = temp->next;
				r = r->next;
			}
		}
		temp->next = l ? l : r;
		temp = dummy->next;
		delete dummy;
		dummy = nullptr;
		return temp;
	}
};
// https://leetcode.cn/problems/sort-list/solutions/9014/148-pai-xu-lian-biao-bottom-to-up-o1-kong-jian-by-/
// @author https://leetcode.cn/u/ivan_allen/