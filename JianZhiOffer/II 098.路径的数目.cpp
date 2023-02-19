#include "header.h"

/*

��ָ Offer II 098. ·������Ŀ

һ��������λ��һ�� m x n ��������Ͻǣ���ʼ������ͼ�б��Ϊ ��Start�� ��
������ÿ��ֻ�����»��������ƶ�һ������������ͼ�ﵽ��������½ǣ�����ͼ�б��Ϊ ��Finish�� ��
���ܹ��ж�������ͬ��·����

ʾ�� 1��
���룺m = 3, n = 7
�����28

ʾ�� 2��
���룺m = 3, n = 2
�����3
���ͣ�
�����Ͻǿ�ʼ���ܹ��� 3 ��·�����Ե������½ǡ�
1. ���� -> ���� -> ����
2. ���� -> ���� -> ����
3. ���� -> ���� -> ����

ʾ�� 3��
���룺m = 7, n = 3
�����28

ʾ�� 4��
���룺m = 3, n = 3
�����6

��ʾ��
1 <= m, n <= 100
��Ŀ���ݱ�֤��С�ڵ��� 2 * 10^9

ע�⣺��������վ 62 ����ͬ�� https://leetcode-cn.com/problems/unique-paths/

*/

// ����¼
class Solution1 {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> memo(m, vector<int>(n));
		return helper(m - 1, n - 1, memo);
	}

private:
	int helper(int i, int j, vector<vector<int>> &memo) {
		if (i == 0 || j == 0) return 1;
		if (memo[i][j] != 0) return memo[i][j];
		memo[i][j] = helper(i - 1, j, memo) + helper(i, j - 1, memo);
		return memo[i][j];
	}
};

// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> dp(m, vector<int>(n));
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (i == 0 || j == 0) dp[i][j] = 1;
				else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};