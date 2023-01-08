#include "header.h"

/*

��ָ Offer II 078. �ϲ���������

����һ���������飬ÿ�������Ѿ����������С����㽫��������ϲ���һ�����������У����غϲ��������

ʾ�� 1��
���룺lists = [[1,4,5],[1,3,4],[2,6]]
�����[1,1,2,3,4,4,5,6]
���ͣ������������£�
[
1->4->5,
1->3->4,
2->6
]
�����Ǻϲ���һ�����������еõ���
1->1->2->3->4->4->5->6

ʾ�� 2��
���룺lists = []
�����[]

ʾ�� 3��
���룺lists = [[]]
�����[]

��ʾ��
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] �� ���� ����
lists[i].length ���ܺͲ����� 10^4

ע�⣺��������վ 23 ����ͬ�� https://leetcode-cn.com/problems/merge-k-sorted-lists/

*/

// ����
class Solution1 {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if (lists.empty()) return nullptr;
		return helper(lists, 0, lists.size() - 1);
	}

private:
	ListNode *helper(vector<ListNode *> &lists, int l, int r) {
		if (l == r) return lists[l];
		int mi = l + (r - l) / 2;
		return merge(helper(lists, l, mi), helper(lists, mi + 1, r));
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

// ���ȼ�����
class Solution2 {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		priority_queue<ListNode *, vector<ListNode *>, decltype(compare) *> pq(compare);
		ListNode *dummy = new ListNode(-1);
		ListNode *cur = dummy;
		for (auto list : lists) {
			if (list) pq.push(list);
		}
		while (!pq.empty()) {
			cur->next = pq.top();
			pq.pop();
			cur = cur->next;
			if (cur->next) pq.push(cur->next);
		}
		cur = dummy->next;
		delete dummy;
		dummy = nullptr;
		return cur;
	}

private:
	static bool compare(ListNode *node1, ListNode *node2) {
		return node1->val > node2->val;
	}
};
// https://leetcode.cn/problems/merge-k-sorted-lists/solutions/219756/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/comments/1383863
// @Comments ���ȶ���Ϊʲô��ȫ���Ž�ȥ����ֻ��k��������н��
// ��Ϊֻ�Ǵ�k���������ǰ�˱Ƚϣ��ͺ����û�й�ϵ�����Բ���Ҫ�������У��������ں���ı�ǰ�������ȫ������Ҳ���ԡ�
// �����ռ临�Ӷ�������ͬʱ���ڶ�����Ԫ�ص����࣬С���ѵĵ���Ҳ�Ứ�����ʱ�䡣