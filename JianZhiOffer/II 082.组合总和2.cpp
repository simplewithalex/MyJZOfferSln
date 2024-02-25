#include "header.h"

/*

LCR 082. ����ܺ� II

����һ����ѡ�˱�ŵļ��� candidates ��һ��Ŀ���� target���ҳ� candidates �����п���ʹ���ֺ�Ϊ target �����
candidates �е�ÿ��������ÿ�������ֻ��ʹ�� һ��
ע�⣺�⼯���ܰ����ظ������

ʾ�� 1:
����: candidates = [10,1,2,7,6,1,5], target = 8,
���:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

ʾ�� 2:
����: candidates = [2,5,2,1,2], target = 5,
���:
[
[1,2,2],
[5]
]

��ʾ:
1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30

ע�⣺��������վ 40 ����ͬ�� https://leetcode-cn.com/problems/combination-sum-ii/

*/

class Solution {
private:
	vector<int> path;
	vector<vector<int>> res;

public:
	vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
		backtrack(candidates, 0, target);
		return res;
	}

private:
	void backtrack(const vector<int> &candidates, int begin, int target) {
		if (target == 0) {
			res.push_back(path);
			return;
		}
		for (int i = begin; i < candidates.size(); ++i) {
			if (target - candidates[i] < 0) return;
			if (i > begin && candidates[i] == candidates[i - 1]) continue;
			path.push_back(candidates[i]);
			backtrack(candidates, i + 1, target - candidates[i]);
			path.pop_back();
		}
	}
};
