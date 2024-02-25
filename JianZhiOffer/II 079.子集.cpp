#include "header.h"

/*

LCR 079. �Ӽ�

����һ���������� nums�������е�Ԫ�� ������ͬ
���ظ��������п��ܵ��Ӽ����ݼ���

�⼯ ���� �����ظ����Ӽ�������԰� ����˳�� ���ؽ⼯

ʾ�� 1��
���룺nums = [1,2,3]
�����[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

ʾ�� 2��
���룺nums = [0]
�����[[],[0]]

��ʾ��
1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums �е�����Ԫ�� ������ͬ

ע�⣺��������վ 78 ����ͬ�� https://leetcode-cn.com/problems/subsets/

*/

class Solution {
private:
	vector<vector<int>> res;

public:
	vector<vector<int>> subsets(vector<int> &nums) {
		vector<int> path;
		backtrack(nums, path, 0);
		return res;
	}

private:
	void backtrack(vector<int> &nums, vector<int> &path, int start) {
		res.push_back(path);
		for (int i = start; i < nums.size(); ++i) {
			path.push_back(nums[i]);
			backtrack(nums, path, i + 1);
			path.pop_back();
		}
	}
};

