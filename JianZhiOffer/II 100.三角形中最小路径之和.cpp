#include "header.h"

/*

��ָ Offer II 100. ����������С·��֮��

����һ�������� triangle���ҳ��Զ����µ���С·���͡�ÿһ��ֻ���ƶ�����һ�������ڵĽ���ϡ�
���ڵĽ�� ������ָ���� �±� �� ��һ�����±� ��ͬ���ߵ��� ��һ�����±� + 1 ��������㡣
Ҳ����˵�������λ�ڵ�ǰ�е��±� i ����ô��һ�������ƶ�����һ�е��±� i �� i + 1 ��

ʾ�� 1��
���룺triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
�����11
���ͣ��������ͼ��ʾ��
2
3 4
6 5 7
4 1 8 3
�Զ����µ���С·����Ϊ 11������2 + 3 + 5 + 1 = 11����

ʾ�� 2��
���룺triangle = [[-10]]
�����-10

��ʾ��
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-10^4 <= triangle[i][j] <= 10^4

���ף������ֻʹ�� O(n) �Ķ���ռ䣨n Ϊ�����ε�����������������������

ע�⣺��������վ 120 ����ͬ�� https://leetcode-cn.com/problems/triangle/

*/

// ����¼
class Solution1 {
public:
	int minimumTotal(vector<vector<int>> &triangle) {
		int rows = triangle.size(), cols = triangle.size();
		vector<vector<int>> memo(rows, vector<int>(cols, INT_MAX));
		int ans = INT_MAX;
		for (int j = 0; j < cols; ++j) {
			ans = min(helper(triangle, rows - 1, j, memo), ans);
		}
		return ans;
	}

private:
	int helper(vector<vector<int>> &triangle, int i, int j,
		vector<vector<int>> &memo) {
		if (memo[i][j] != INT_MAX) return memo[i][j];
		if (i == 0) {
			return triangle[0][0];
		}
		if (j == 0) {
			return memo[i][j] = helper(triangle, i - 1, j, memo) + triangle[i][j];
		}
		if (j == triangle[i].size() - 1) {
			return memo[i][j] = helper(triangle, i - 1, j - 1, memo) + triangle[i][j];
		}
		return memo[i][j] = min(helper(triangle, i - 1, j, memo),
			helper(triangle, i - 1, j - 1, memo)) + triangle[i][j];
	}
};

// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int minimumTotal(vector<vector<int>> &triangle) {
		int rows = triangle.size(), cols = triangle.size();
		vector<vector<int>> dp(rows, vector<int>(cols));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < rows; ++i) {
			for (int j = 0; j <= i; ++j) {
				if (j == 0) dp[i][j] = dp[i - 1][0] + triangle[i][j];
				else if (j == i) dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
				else dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j];
			}
		}
		return *min_element(dp[rows - 1].begin(), dp[rows - 1].end());
	}
};

// ����Ŀ���Է�������ƣ��߼����������ɲο���
// https://leetcode.cn/problems/triangle/solutions/329394/di-gui-ji-yi-hua-dp-bi-xu-miao-dong-by-sweetiee/