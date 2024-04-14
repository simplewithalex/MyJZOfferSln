#include "header.h"

/*

LCR 103. ��Ǯ�һ�

����һ���������� coins����ʾ��ͬ����Ӳ�ң��Լ�һ������ amount����ʾ�ܽ�

���㲢���ؿ��Դճ��ܽ������� ���ٵ�Ӳ�Ҹ��������û���κ�һ��Ӳ�����������ܽ����� -1��

�������Ϊÿ��Ӳ�ҵ����������޵ġ�

ʾ�� 1��
���룺coins = [1, 2, 5], amount = 11
�����3
���ͣ�11 = 5 + 5 + 1

ʾ�� 2��
���룺coins = [2], amount = 3
�����-1

ʾ�� 3��
���룺coins = [1], amount = 0
�����0

��ʾ��
1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4

ע�⣺��������վ 322 ����ͬ�� https://leetcode-cn.com/problems/coin-change/

*/

// ��ȫ����������
// ����¼
class Solution1 {
private:
	vector<vector<int>> memo;

public:
	int coinChange(vector<int> &coins, int amount) {
		int len = coins.size();
		memo.resize(len + 1, vector<int>(amount + 1, -1));
		int res = helper(coins, len, amount);
		return res < INT_MAX / 2 ? res : -1;
	}

private:
	int helper(vector<int> &coins, int idx, int remains) {
		if (idx == 0) return remains == 0 ? 0 : INT_MAX / 2;
		if (memo[idx][remains] != -1) return memo[idx][remains];
		int res = 0;
		if (remains < coins[idx - 1]) {
			res = helper(coins, idx - 1, remains);
		} else {
			res = min(helper(coins, idx - 1, remains),
				helper(coins, idx, remains - coins[idx - 1]) + 1);
		}
		return memo[idx][remains] = res;
	}
};


// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int coinChange(vector<int> &coins, int amount) {
		int len = coins.size();
		vector<vector<int>> dp(len + 1, vector<int>(amount + 1, INT_MAX / 2));
		dp[0][0] = 0;
		for (int i = 1; i <= len; ++i) {
			for (int j = 0; j <= amount; ++j) {
				if (j < coins[i - 1]) dp[i][j] = dp[i - 1][j];
				else dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
			}
		}
		int res = dp[len][amount];
		return res < INT_MAX / 2 ? res : -1;
	}
};

// �Ż�Ϊһά����
class Solution3 {
public:
	int coinChange(vector<int> &coins, int amount) {
		int len = coins.size();
		vector<int> dp(amount + 1, INT_MAX / 2);
		dp[0] = 0;
		for (int coin : coins) {
			for (int i = coin; i <= amount; ++i) {
				dp[i] = min(dp[i], dp[i - coin] + 1);
			}
		}
		return dp[amount] < INT_MAX / 2 ? dp[amount] : -1;
	}
};

