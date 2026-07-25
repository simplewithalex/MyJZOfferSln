#include "header.h"

/*

数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

示例 1:
输入: [7,5,6,4]
输出: 5
  
限制：0 <= 数组长度 <= 50000

*/

/*

LCR 170. 交易逆序对的总数

在股票交易中，如果前一天的股价高于后一天的股价，则可以认为存在一个「交易逆序对」
请设计一个程序，输入一段时间内的股票交易记录 record，返回其中存在的「交易逆序对」总数

示例 1：
输入：record = [9, 7, 5, 4, 6]
输出：8
解释：交易中的逆序对为 (9, 7), (9, 5), (9, 4), (9, 6), (7, 5), (7, 4), (7, 6), (5, 4)

提示：
0 <= record.length <= 50000

*/


// 归并排序
class Solution {
public:
	int cnt = 0;
	int reversePairs(vector<int> &record) {
		int len = record.size();
		mergeSort(record, 0, len - 1);
		return cnt;
	}
	void mergeSort(vector<int> &record, int lo, int hi) {
		if (lo >= hi) return;
		int mi = lo + (hi - lo) / 2;
		mergeSort(record, lo, mi);
		mergeSort(record, mi + 1, hi);
		merge(record, lo, hi, mi);
	}
	void merge(vector<int> &record, int lo, int hi, int mi) {
		int j = mi + 1;
		for (int i = lo; i <= mi; ++i) {
			while (j <= hi && record[j] < record[i]) ++j;
			cnt += j - (mi + 1);
		}
		inplace_merge(record.begin() + lo, record.begin() + mi + 1,
			record.begin() + hi + 1);
	}
};

// 线段树单点更新
struct Node {
	Node *left;
	Node *right;
	int val;
	Node() : left(nullptr), right(nullptr), val(0) {}
};

class Solution1 {
public:
	void update(Node *node, int start, int end, int idx) {
		if (start == end) {
			++node->val;
			return;
		}
		int mi = start + ((long long)end - (long long)start) / 2;
		if (!node->left) node->left = new Node();
		if (!node->right) node->right = new Node();
		if (idx <= mi) update(node->left, start, mi, idx);
		else update(node->right, mi + 1, end, idx);
		node->val = node->left->val + node->right->val;
	}
	int query(Node *node, int start, int end, int l, int r) {
		if (!node) return 0;
		if (l <= start && r >= end) return node->val;
		int mi = start + ((long long)end - (long long)start) / 2, ans = 0;
		if (l <= mi) ans += query(node->left, start, mi, l, r);
		if (r > mi) ans += query(node->right, mi + 1, end, l, r);
		return ans;
	}
	int reversePairs(vector<int> &record) {
		int len = record.size();
		if (len == 0) return 0;
		int maxNum = *max_element(record.begin(), record.end());
		int minNum = *min_element(record.begin(), record.end());
		Node *root = new Node();
		int cnt = 0;
		for (int i = len - 1; i >= 0; --i) {
			int cur = record[i] - 1;
			cnt += cur >= minNum ? query(root, minNum, maxNum, minNum, cur) : 0;
			update(root, minNum, maxNum, record[i]);
		}
		return cnt;
	}
};

class Solution2 {
public:
	int reversePairs(vector<int> &nums) 
	{
		if (nums.empty()) return 0;
		int count = 0;
		int len = nums.size();
		mergeSort(nums, 0, len, count);
		return count;
	}
	int mergeSort(vector<int> &data, int lo, int hi, int &count)
	{
		if (hi - lo < 2) return lo;
		int mi = (lo + hi) >> 1;
		int left = 0, right = 0;
		left = mergeSort(data, lo, mi, count);
		right = mergeSort(data, mi, hi, count);
		while (left >= lo && right >= mi)
		{
			if (data[left] > data[right])
			{
				count += right - mi + 1;
				--left;
			}
			else
			{
				--right;
			}
		}
		merge(data, lo, mi, hi);
		return hi - 1;
	}
	void merge(vector<int> &data, int lo, int mi, int hi)
	{
		int leftNum = mi - lo;
		vector<int> temp(leftNum, 0);
		for (int i = 0, j = lo; i < leftNum; ++i, ++j) temp[i] = data[j];
		int i = 0, j = mi, k = lo;
		while (i < leftNum && j < hi)
		{
			if (temp[i] <= data[j]) data[k++] = temp[i++];
			else data[k++] = data[j++];
		}
		while (i < leftNum) data[k++] = temp[i++];
	}
};
