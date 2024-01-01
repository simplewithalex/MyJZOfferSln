#include "header.h"

/*

LCR 060. ǰ K ����ƵԪ��

����һ���������� nums ��һ������ k �����㷵�����г���Ƶ��ǰ k �ߵ�Ԫ��
����԰� ����˳�� ���ش�

ʾ�� 1:
����: nums = [1,1,1,2,2,3], k = 2
���: [1,2]

ʾ�� 2:
����: nums = [1], k = 1
���: [1]

��ʾ��
1 <= nums.length <= 10^5
k ��ȡֵ��Χ�� [1, �����в���ͬ��Ԫ�صĸ���]
��Ŀ���ݱ�֤��Ψһ�����仰˵��������ǰ k ����ƵԪ�صļ�����Ψһ��

���ף���������㷨��ʱ�临�Ӷ� ���� ���� O(nlogn) ������ n �������С

ע�⣺��������վ 347 ����ͬ��https://leetcode-cn.com/problems/top-k-frequent-elements/

*/


class Solution {
private:
	static bool compare(pair<int, int> &p1, pair<int, int> &p2) {
		return p1.second > p2.second;
	}

public:
	vector<int> topKFrequent(vector<int> &nums, int k) {
		unordered_map<int, int> occurrences;
		for (const int &n : nums) ++occurrences[n];
		priority_queue<pair<int, int>, vector<pair<int, int>>,
			decltype(compare) *> pq(compare);
		for (const auto &p : occurrences) {
			pq.push(p);
			if (pq.size() > k) pq.pop();
		}
		vector<int> res;
		while (!pq.empty()) {
			res.push_back(pq.top().first);
			pq.pop();
		}
		return res;
	}
};
