#include "header.h"

/*

LCR 071. ��Ȩ�����ѡ��

����һ�� �±�� 0 ��ʼ ������������ w, ���� w[i] ����� i ���±��Ȩ��
����ʵ��һ������ pickIndex, ������ ����� �ӷ�Χ [0, w.length - 1] �ڣ��� 0 �� w.length - 1��ѡ��������һ���±�, ѡȡ�±� i �� ���� Ϊ w[i] / sum(w)

���磬���� w = [1, 3], ��ѡ�±� 0 �ĸ���Ϊ 1 / (1 + 3) = 0.25, ��ѡȡ�±� 1 �ĸ���Ϊ 3 / (1 + 3) = 0.75

ʾ�� 1��
���룺
["Solution","pickIndex"]
[[[1]],[]]
�����
[null,0]
���ͣ�
Solution solution = new Solution([1]);
solution.pickIndex(); // ���� 0����Ϊ������ֻ��һ��Ԫ�أ�����Ψһ��ѡ���Ƿ����±� 0��

ʾ�� 2��
���룺
["Solution","pickIndex","pickIndex","pickIndex","pickIndex","pickIndex"]
[[[1,3]],[],[],[],[],[]]
�����
[null,1,1,1,1,0]
���ͣ�
Solution solution = new Solution([1, 3]);
solution.pickIndex(); // ���� 1�������±� 1�����ظ��±����Ϊ 3/4 ��
solution.pickIndex(); // ���� 1
solution.pickIndex(); // ���� 1
solution.pickIndex(); // ���� 1
solution.pickIndex(); // ���� 0�������±� 0�����ظ��±����Ϊ 1/4 ��

��������һ��������⣬�������𰸣����������������Ա���Ϊ����ȷ��:
[null,1,1,1,1,0]
[null,1,1,1,1,1]
[null,1,1,1,0,0]
[null,1,1,1,0,1]
[null,1,0,1,0,0]
......
��������

��ʾ��
1 <= w.length <= 10^4
1 <= w[i] <= 10^5
pickIndex �������ò����� 10^4 ��

ע�⣺��������վ 528 ����ͬ�� https://leetcode-cn.com/problems/random-pick-with-weight/


*/


class Solution1 {
private:
	vector<int> sum;

public:
	Solution1(vector<int> &w) {
		int len = w.size();
		sum.resize(len + 1);
		for (int i = 0; i < len; ++i) sum[i + 1] = sum[i] + w[i];
	}

	int pickIndex() {
		int len = sum.size();
		int lo = 1, hi = len - 1;
		int target = rand() % sum[len - 1] + 1;
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			sum[mi] < target ? lo = mi + 1 : hi = mi;
		}
		return lo - 1;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(w);
* int param_1 = obj->pickIndex();
*/

/*

�÷���������һ�������鹹������е��±�Ԫ�����У�
Ȼ������������ܳ�����rand������������ĸ��±�Ԫ����

���� [3, 1, 2, 4]������Թ���һ��������[0, 0, 0, 1, 2, 2, 3, 3, 3, 3]
���������Ŀ����������������Χ�ǳ��󣬹�������������ڴ泬��
���ѡ��ʹ��ǰ׺�͵ķ�����ͨ�����ֲ��ҽ��

*/

// https://leetcode.cn/problems/random-pick-with-weight/solutions/966628/gong-shui-san-xie-yi-ti-shuang-jie-qian-8bx50/
// @author https://leetcode.cn/u/ac_oier/



class Solution2 {
private:
	int bid = 0;
	int cid = 0;
	vector<pair<int, int>> buckets;

public:
	Solution2(vector<int> &w) {
		int len = w.size();
		double sum = 0, minNum = INT_MAX;
		for (int n : w) {
			sum += n;
			minNum = min(minNum, (double)n);
		}
		double minFrac = minNum / sum;
		int k = 1;
		while (minFrac * k < 1) k *= 10;
		for (int i = 0; i < len; ++i) {
			int cnt = w[i] / sum * k;
			buckets.push_back({ i, cnt });
		}
	}

	int pickIndex() {
		pair<int, int> p = buckets[bid];
		int id = p.first, cnt = p.second;
		while (cid >= cnt) {
			++bid;
			if (bid == buckets.size()) bid = 0;
			cid = 0;
			p = buckets[bid];
			id = p.first;
			cnt = p.second;
		}
		++cid;
		return id;
	}
};

/**
* Your Solution object will be instantiated and called as such:
* Solution* obj = new Solution(w);
* int param_1 = obj->pickIndex();
*/


// https://leetcode.cn/problems/random-pick-with-weight/solutions/966628/gong-shui-san-xie-yi-ti-shuang-jie-qian-8bx50/
// @author https://leetcode.cn/u/ac_oier/
