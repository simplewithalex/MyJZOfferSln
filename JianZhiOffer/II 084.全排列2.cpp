#include "header.h"

/*

LCR 084. ȫ���� II

����һ���ɰ����ظ����ֵ��������� nums��������˳�� ���������в��ظ���ȫ����

ʾ�� 1��
���룺nums = [1,1,2]
�����
[[1,1,2],
[1,2,1],
[2,1,1]]

ʾ�� 2��
���룺nums = [1,2,3]
�����[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

��ʾ��
1 <= nums.length <= 8
-10 <= nums[i] <= 10

ע�⣺��������վ 47 ����ͬ�� https://leetcode-cn.com/problems/permutations-ii/

*/

class Solution {
private:
	vector<vector<int>> res;
	vector<int> path;
	int used = 0;

public:
	vector<vector<int>> permuteUnique(vector<int> &nums) {
		int len = nums.size();
		sort(nums.begin(), nums.end());
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
			if (i > 0 && nums[i] == nums[i - 1] && !(used & (1 << (i - 1)))) {
				continue;
			}
			path.push_back(nums[i]);
			used |= (1 << i);
			backtrack(nums);
			path.pop_back();
			used &= ~(1 << i);
		}
	}
};

