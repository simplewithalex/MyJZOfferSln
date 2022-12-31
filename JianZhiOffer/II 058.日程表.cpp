#include "header.h"

/*

��ָ Offer II 058. �ճ̱�

ʵ��һ�� MyCalendar �����������ճ̰��š����Ҫ��ӵ��ճ̰��Ų������ �ظ�Ԥ�� ������Դ洢����µ��ճ̰��š�
�������ճ̰�����һЩʱ���ϵĽ���ʱ�����������ճ̰��Ŷ���ͬһʱ���ڣ����ͻ���� �ظ�Ԥ�� ��
�ճ̿�����һ������ start �� end ��ʾ�������ʱ���ǰ뿪���䣬�� [start, end), ʵ�� x �ķ�ΧΪ��  start <= x < end ��

ʵ�� MyCalendar �ࣺ
MyCalendar() ��ʼ����������
boolean book(int start, int end) ������Խ��ճ̰��ųɹ���ӵ������ж����ᵼ���ظ�Ԥ�������� true �����򣬷��� false ���Ҳ�Ҫ�����ճ̰�����ӵ������С�

ʾ����
���룺
["MyCalendar", "book", "book", "book"]
[[], [10, 20], [15, 25], [20, 30]]
�����
[null, true, false, true]

���ͣ�
MyCalendar myCalendar = new MyCalendar();
myCalendar.book(10, 20); // return True
myCalendar.book(15, 25); // return False ������ճ̰��Ų�����ӵ������У���Ϊʱ�� 15 �Ѿ�����һ���ճ̰���Ԥ���ˡ�
myCalendar.book(20, 30); // return True ������ճ̰��ſ�����ӵ������У���Ϊ��һ���ճ̰���Ԥ����ÿ��ʱ�䶼С�� 20 ���Ҳ�����ʱ�� 20 ��

��ʾ��
0 <= start < end <= 10^9
ÿ���������������� book �����Ĵ�����಻���� 1000 �Ρ�

ע�⣺��������վ 729 ����ͬ�� https://leetcode-cn.com/problems/my-calendar-i/

*/

// �������
class MyCalendar1 {
private:
	vector<pair<int, int>> booked;
public:
	MyCalendar1() {}

	bool book(int start, int end) {
		for (const auto &p : booked) {
			if (p.first < end && p.second > start) return false;
		}
		booked.push_back(pair<int, int>{start, end});
		return true;
	}
};


// ���ֲ���
class MyCalendar2 {
private:
	set<pair<int, int>> booked;
public:
	MyCalendar2() {

	}

	bool book(int start, int end) {
		auto it = booked.lower_bound({ end,0 });
		if (it == booked.begin() || (--it)->second <= start) {
			booked.insert({ start,end });
			return true;
		}
		return false;
	}
};

// �����߶���
struct Node {
	Node *left;
	Node *right;
	int val;
	int add;
	Node() : left(nullptr), right(nullptr), val(0), add(0) {}
};

class MyCalendar3 {
private:
	Node *root = new Node();
	int N = (int)1E9;

private:
	void pushUp(Node *node) {
		node->val = max(node->left->val, node->right->val);
	}
	void pushDown(Node *node) {
		if (!node->left) node->left = new Node();
		if (!node->right) node->right = new Node();
		if (node->add == 0) return;
		node->left->val += node->add;
		node->right->val += node->add;
		node->left->add += node->add;
		node->right->add += node->add;
		node->add = 0;
	}

	void update(Node *node, int start, int end, int l, int r, int val) {
		if (l <= start && r >= end) {
			node->val += val;
			node->add += val;
			return;
		}
		pushDown(node);
		int mid = start + (end - start) / 2;
		if (l <= mid) update(node->left, start, mid, l, r, val);
		if (r > mid) update(node->right, mid + 1, end, l, r, val);
		pushUp(node);
	}

	int query(Node *node, int start, int end, int l, int r) {
		if (l <= start && end <= r) return node->val;
		pushDown(node);
		int mid = start + (end - start) / 2, ans = 0;
		if (l <= mid) ans = query(node->left, start, mid, l, r);
		if (r > mid) ans = max(ans, query(node->right, mid + 1, end, l, r));
		return ans;
	}

public:
	MyCalendar3() {}

	bool book(int start, int end) {
		if (query(root, 0, N, start, end - 1) != 0) return false;
		update(root, 0, N, start, end - 1, 1);
		return true;
	}
};
// https://leetcode.cn/problems/my-calendar-i/solutions/1646079/by-lfool-xvpv/
// @author https://leetcode.cn/u/lfool/

/**
* Your MyCalendar object will be instantiated and called as such:
* MyCalendar* obj = new MyCalendar();
* bool param_1 = obj->book(start,end);
*/