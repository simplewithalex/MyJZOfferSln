#include "header.h"

/*

LCR 083. ȫ����

����һ�������ظ����ֵ����� nums�����������п��ܵ�ȫ����
����� ������˳�� ���ش�

ʾ�� 1��
���룺nums = [1,2,3]
�����[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

ʾ�� 2��
���룺nums = [0,1]
�����[[0,1],[1,0]]

ʾ�� 3��
���룺nums = [1]
�����[[1]]

��ʾ��
1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums �е��������� ������ͬ

ע�⣺��������վ 46 ����ͬ��https://leetcode-cn.com/problems/permutations/

*/

class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
	int used = 0;

public:
	vector<vector<int>> permute(vector<int> &nums) {
		backtrack(nums);
		return res;
	}

private:
	void backtrack(const vector<int> &nums) {
		if (path.size() == nums.size()) {
			res.push_back(path);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (used & (1 << i)) continue;
			path.push_back(nums[i]);
			used |= (1 << i);
			backtrack(nums);
			path.pop_back();
			used &= ~(1 << i);
		}
	}
};

