#include "header.h"

/*

��ָ Offer II 102. �Ӽ���Ŀ��ֵ

����һ���������� nums ��һ������ target���������е�ÿ������ǰ��� '+' �� '-' ��Ȼ�������������������Թ���һ�����ʽ
���磬nums = [2, 1] �������� 2 ֮ǰ��� '+' ���� 1 ֮ǰ��� '-' ��Ȼ���������õ����ʽ "+2-1"
���ؿ���ͨ��������������ġ����������� target �Ĳ�ͬ ���ʽ ����Ŀ

ʾ�� 1��
���룺nums = [1,1,1,1,1], target = 3
�����5
���ͣ�һ���� 5 �ַ���������Ŀ���Ϊ 3 ��
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

ʾ�� 2��
���룺nums = [1], target = 1
�����1

��ʾ��
1 <= nums.length <= 20
0 <= nums[i] <= 1000
0 <= sum(nums[i]) <= 1000
-1000 <= target <= 1000

ע�⣺��������վ 494 ����ͬ�� https://leetcode-cn.com/problems/target-sum/

*/

// ת��Ϊ 0-1���� ����

// ����¼
class Solution1 {
public:
	int findTargetSumWays(vector<int> &nums, int target) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum < abs(target)) return 0;
		if ((sum - target) & 1) return 0;
		int len = nums.size(), neg = (sum - target) / 2;
		vector<vector<int>> memo(len + 1, vector<int>(neg + 1, -1));
		return helper(nums, len, neg, memo);
	}

private:
	int helper(vector<int> &nums, int idx, int target, vector<vector<int>> &memo) {
		if (idx == 0) return target == 0 ? 1 : 0;
		if (target < 0) return 0;
		if (memo[idx][target] != -1) return memo[idx][target];
		memo[idx][target] = helper(nums, idx - 1, target, memo) +
							helper(nums, idx - 1, target - nums[idx - 1], memo);
		return memo[idx][target];
	}
};


// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int findTargetSumWays(vector<int> &nums, int target) {
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum < abs(target)) return 0;
		if ((sum - target) & 1) return 0;
		int len = nums.size(), neg = (sum - target) / 2;
		vector<vector<int>> dp(len + 1, vector<int>(neg + 1, -1));
		for (int i = 0; i <= len; ++i) {
			for (int j = 0; j <= neg; ++j) {
				if (i == 0 && j == 0) dp[i][j] = 1;
				else if (i == 0) dp[i][j] = 0;
				else if (j < nums[i - 1]) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
			}
		}
		return dp[len][neg];
	}
};

// https://leetcode.cn/problems/target-sum/solutions/816361/mu-biao-he-by-leetcode-solution-o0cp/
// @author LeetCode�ٷ����

// https://leetcode.cn/problems/target-sum/solutions/816711/gong-shui-san-xie-yi-ti-si-jie-dfs-ji-yi-et5b/comments/976370
// @author https://leetcode.cn/u/seven-w/