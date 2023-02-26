#include "header.h"

/*

��ָ Offer II 101. �ָ�Ⱥ��Ӽ�

����һ��ֻ�����������ķǿ�����nums�������ж��Ƿ���Խ��������ָ�������Ӽ���ʹ�������Ӽ���Ԫ�غ���ȡ�

ʾ�� 1��
���룺nums = [1,5,11,5]
�����true
���ͣ�������Էָ�� [1, 5, 5] �� [11]

ʾ�� 2��
���룺nums = [1,2,3,5]
�����false
���ͣ����鲻�ָܷ������Ԫ�غ���ȵ��Ӽ���

��ʾ��
1 <= nums.length <= 200
1 <= nums[i] <= 100

ע�⣺��������վ 416 ����ͬ�� https://leetcode-cn.com/problems/partition-equal-subset-sum/

*/

// ת��Ϊ 0-1���� ����

// ����¼
class Solution1 {
public:
	bool canPartition(vector<int> &nums) {
		int len = nums.size();
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum & 1) return false;
		vector<vector<char>> memo(len + 1, vector<char>((sum / 2) + 1, -1));
		return helper(nums, len, sum / 2, memo);
	}

private:
	bool helper(vector<int> &nums, int idx, int target, vector<vector<char>> &memo) {
		if (target == 0) return true;
		else if (idx == 0 || target < 0) return false;
		if (memo[idx][target] != -1) return memo[idx][target];
		memo[idx][target] = helper(nums, idx - 1, target - nums[idx - 1], memo) ||
							helper(nums, idx - 1, target, memo);
		return memo[idx][target];
	}
};

// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	bool canPartition(vector<int> &nums) {
		int len = nums.size();
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum & 1) return false;
		int target = sum / 2;
		vector<vector<char>> dp(len + 1, vector<char>(target + 1, false));
		for (int i = 0; i <= len; ++i) {
			for (int j = 0; j <= target; ++j) {
				if (i == 0 && j == 0) dp[i][j] = true;
				else if (i == 0) dp[i][j] = false;
				else if (j == 0) dp[i][j] = true;
				else if (j < nums[i - 1]) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
			}
		}
		return dp[len][target];
	}
};