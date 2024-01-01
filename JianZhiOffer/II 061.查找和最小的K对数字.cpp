#include "header.h"

/*

LCR 061. ���Һ���С�� K ������

���������Էǵݼ�˳�����е��������� nums1 �� nums2, �Լ�һ������ k

����һ��ֵ (u,v)�����е�һ��Ԫ������ nums1���ڶ���Ԫ������ nums2

���ҵ�����С�� k ������ (u1,v1),  (u2,v2)  ...  (uk,vk)

ʾ�� 1:
����: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
���: [1,2],[1,4],[1,6]
����: ���������е�ǰ 3 ������
[1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]

ʾ�� 2:
����: nums1 = [1,1,2], nums2 = [1,2,3], k = 2
���: [1,1],[1,1]
����: ���������е�ǰ 2 ������
[1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]

ʾ�� 3:
����: nums1 = [1,2], nums2 = [3], k = 3
���: [1,3],[2,3]
����: Ҳ�������������е����Զ�������:[1,3],[2,3]

��ʾ:
1 <= nums1.length, nums2.length <= 10^5
-10^9 <= nums1[i], nums2[i] <= 10^9
nums1 �� nums2 ��Ϊ ��������
1 <= k <= 10^4
k <= nums1.length * nums2.length

ע�⣺��������վ 373 ����ͬ��https://leetcode-cn.com/problems/find-k-pairs-with-smallest-sums/


*/


// ���ֲ���
class Solution1 {
public:
	vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
		int len1 = nums1.size(), len2 = nums2.size();
		vector<vector<int>> res;
		int lo = nums1[0] + nums2[0], hi = nums1[len1 - 1] + nums2[len2 - 1];
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			if (check(nums1, nums2, mi, k)) hi = mi;
			else lo = mi + 1;
		}
		int sum = lo;
		for (int i = 0; i < len1; ++i) {
			for (int j = 0; j < len2; ++j) {
				if (nums1[i] + nums2[j] < sum) res.push_back({ nums1[i], nums2[j] });
				else break;
			}
		}

		// ���������ҵ�����֮��Ϊsum�����Ҷ˵�
		for (int i = 0; i < len1 && res.size() < k; ++i) {
			int a = nums1[i], b = sum - a;
			int lo = 0, hi = len2 - 1;
			// �ҵ���˵�
			while (lo < hi) {
				int mi = lo + (hi - lo) / 2;
				if (nums2[mi] < b) lo = mi + 1;
				else hi = mi;
			}
			if (nums2[lo] != b) continue;
			int l = lo;
			// �ҵ��Ҷ˵�
			lo = 0, hi = len2 - 1;
			while (lo < hi) {
				int mi = lo + (hi - lo + 1) / 2;
				if (nums2[mi] > b) hi = mi - 1;
				else lo = mi;
			}
			int r = lo;
			for (int i = l; i <= r && res.size() < k; ++i) res.push_back({ a, b });
		}
		return res;
	}

private:
	bool check(const vector<int> &nums1, const vector<int> &nums2, int mi, int k) {
		int cnt = 0;
		for (int i = 0; i < nums1.size(); ++i) {
			for (int j = 0; j < nums2.size() && cnt < k; ++j) {
				if (nums1[i] + nums2[j] <= mi) ++cnt;
				else break;
			}
		}
		return cnt == k;
	}
};


// ��·�鲢
class Solution2 {
public:
	vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k) {
		vector<vector<int>> res;
		bool flag = true;
		int len1 = nums1.size(), len2 = nums2.size();
		if (len1 > len2) {
			swap(nums1, nums2);
			swap(len1, len2);
			flag = false;
		}
		auto cmp = [&](const pair<int, int> &p1, const pair<int, int> &p2) {
			return nums1[p1.first] + nums2[p1.second] >
				   nums1[p2.first] + nums2[p2.second];
		};
		priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
		for (int i = 0; i < min(len1, k); ++i) pq.push({ i, 0 });
		while (res.size() < k && !pq.empty()) {
			pair<int, int> tmp = pq.top();
			pq.pop();
			flag ? res.push_back({ nums1[tmp.first], nums2[tmp.second] })
				 : res.push_back({ nums2[tmp.second], nums1[tmp.first] });
			if (tmp.second + 1 < len2) pq.push({ tmp.first, tmp.second + 1 });
		}
		return res;
	}
};
// https://leetcode.cn/problems/find-k-pairs-with-smallest-sums/solutions/1209848/gong-shui-san-xie-duo-lu-gui-bing-yun-yo-pgw5/
// @author https://leetcode.cn/u/ac_oier/

