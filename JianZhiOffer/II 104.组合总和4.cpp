#include "header.h"

/*

LCR 104. ����ܺ� ��

����һ���� ��ͬ ������ɵ����� nums����һ��Ŀ������ target
����� nums ���ҳ��������ܺ�Ϊ target ��Ԫ����ϵĸ���
��Ŀ���ݱ�֤�𰸷��� 32 λ������Χ

ʾ�� 1��
���룺nums = [1,2,3], target = 4
�����7
���ͣ�
���п��ܵ����Ϊ��
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
��ע�⣬˳��ͬ�����б�������ͬ�����

ʾ�� 2��
���룺nums = [9], target = 3
�����0

��ʾ��
1 <= nums.length <= 200
1 <= nums[i] <= 1000
nums �е�����Ԫ�� ������ͬ
1 <= target <= 1000

���ף���������������к��и����ᷢ��ʲô�������������ֱ仯��������������֣���Ҫ����Ŀ�������Щ����������

ע�⣺��������վ 377 ����ͬ��https://leetcode-cn.com/problems/combination-sum-iv/

*/

class Solution1 {
private:
	vector<int> memo;

public:
	int combinationSum4(vector<int> &nums, int target) {
		memo.resize(target + 1, -1);
		return helper(nums, target);
	}
	int helper(const vector<int> &nums, int target) {
		if (target < 0) return 0;
		if (target == 0) return 1;
		if (memo[target] != -1) return memo[target];
		int res = 0;
		for (int i = 0; i < nums.size(); ++i) {
			res += helper(nums, target - nums[i]);
		}
		return memo[target] = res;
	}
};

class Solution2 {
public:
	int combinationSum4(vector<int> &nums, int target) {
		vector<int> dp(target + 1, 0);
		dp[0] = 1;
		for (int i = 1; i <= target; ++i) {
			for (const int n : nums) {
				if (i >= n) dp[i] = (dp[i] + (unsigned int)(dp[i - n])) % INT_MAX;
			}
		}
		return dp[target];
	}
};

