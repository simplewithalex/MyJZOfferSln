#include "header.h"

/*

��ָ Offer II 099. ��С·��֮��

����һ�������Ǹ������� m x n ���� grid�����ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��
˵����ÿ��ֻ�����»��������ƶ�һ����

ʾ�� 1��
���룺grid = [[1,3,1],[1,5,1],[4,2,1]]
�����7
���ͣ���Ϊ·�� 1��3��1��1��1 ���ܺ���С��

ʾ�� 2��
���룺grid = [[1,2,3],[4,5,6]]
�����12

��ʾ��
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 100

ע�⣺��������վ 64 ����ͬ�� https://leetcode-cn.com/problems/minimum-path-sum/

*/

// ����¼
class Solution1 {
public:
	int minPathSum(vector<vector<int>> &grid) {
		int rows = grid.size(), cols = grid[0].size();
		vector<vector<int>> memo(rows, vector<int>(cols));
		return helper(grid, rows - 1, cols - 1, memo);
	}

private:
	int helper(vector<vector<int>> &grid, int i, int j,
		vector<vector<int>> &memo) {
		if (memo[i][j] != 0) return memo[i][j];
		if (i == 0 && j == 0) return grid[i][j];
		if (i == 0) return memo[i][j] = grid[i][j] + helper(grid, i, j - 1, memo);
		if (j == 0) return memo[i][j] = grid[i][j] + helper(grid, i - 1, j, memo);
		memo[i][j] = min(helper(grid, i - 1, j, memo), helper(grid, i, j - 1, memo)) + grid[i][j];
		return memo[i][j];
	}
};

// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int minPathSum(vector<vector<int>> &grid) {
		int rows = grid.size(), cols = grid[0].size();
		vector<vector<int>> dp(rows, vector<int>(cols));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (i == 0 && j == 0) dp[i][j] = grid[i][j];
				else if (i == 0) dp[i][j] = dp[i][j - 1] + grid[i][j];
				else if (j == 0) dp[i][j] = dp[i - 1][j] + grid[i][j];
				else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
		return dp[rows - 1][cols - 1];
	}
};
