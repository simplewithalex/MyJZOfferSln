#include "header.h"

/*

LCR 080. ���

������������ n �� k�����ط�Χ [1, n] �����п��ܵ� k ��������ϡ�
����԰� �κ�˳�� ���ش𰸡�

ʾ�� 1��
���룺n = 4, k = 2
�����
[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]

ʾ�� 2��
���룺n = 1, k = 1
�����[[1]]

��ʾ��
1 <= n <= 20
1 <= k <= n

ע�⣺��������վ 77 ����ͬ�� https://leetcode-cn.com/problems/combinations/

*/


class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		if (k <= 0 || n < k) return res;
		vector<int> path;
		backtrack(n, k, 1, path, res);
		return res;
	}

private:
	void backtrack(int n, int k, int start, vector<int> &path,
		vector<vector<int>> &res) {
		if (path.size() == k) {
			res.push_back(path);
			return;
		}
		for (int i = start; i <= n - (k - path.size()) + 1; ++i) {
			path.push_back(i);
			backtrack(n, k, i + 1, path, res);
			path.pop_back();
		}
	}
};
