#include "header.h"

/*

LCR 081. ����ܺ�

����һ�� ���ظ�Ԫ�� ���������� candidates ��һ��Ŀ������ target
�ҳ� candidates �п���ʹ���ֺ�ΪĿ���� target �����в�ͬ��ϲ����б���ʽ����
����԰� ����˳�� ������Щ���

candidates �е� ͬһ�� ���ֿ��� �������ظ���ѡȡ
�������һ�����ֵı�ѡ������ͬ������������ǲ�ͬ��
���ڸ��������룬��֤��Ϊ target �Ĳ�ͬ��������� 150 ��

ʾ�� 1��
���룺candidates = [2,3,6,7], target = 7
�����[[2,2,3],[7]]
���ͣ�
2 �� 3 �����γ�һ���ѡ��2 + 2 + 3 = 7 ��ע�� 2 ����ʹ�ö��
7 Ҳ��һ����ѡ�� 7 = 7
�������������

ʾ�� 2��
����: candidates = [2,3,5], target = 8
���: [[2,2,2,2],[2,3,3],[3,5]]

ʾ�� 3��
����: candidates = [2], target = 1
���: []

��ʾ��
1 <= candidates.length <= 30
2 <= candidates[i] <= 40
candidates ������Ԫ�� ������ͬ
1 <= target <= 40

ע�⣺��������վ 39 ����ͬ�� https://leetcode-cn.com/problems/combination-sum/

*/

class Solution {
private:
	vector<int> path;
	vector<vector<int>> res;

public:
	vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
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
			path.push_back(candidates[i]);
			backtrack(candidates, i, target - candidates[i]);
			path.pop_back();
		}
	}
};
