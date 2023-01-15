#include "header.h"

/*

������һ�ŷ��ӹ�n����ÿ�����ӿ��Ա���ˢ�ɺ�ɫ����ɫ������ɫ��������ɫ�е�һ�֣�����Ҫ��ˢ���еķ��Ӳ���ʹ�����ڵ�����������ɫ������ͬ��
��Ȼ����Ϊ�г��ϲ�ͬ��ɫ����ļ۸�ͬ�����Է��ӷ�ˢ�ɲ�ͬ��ɫ�Ļ��ѳɱ�Ҳ�ǲ�ͬ�ġ�
ÿ�����ӷ�ˢ�ɲ�ͬ��ɫ�Ļ�������һ�� n x 3 ������������ costs ����ʾ�ġ�
���磬costs[0][0] ��ʾ�� 0 �ŷ��ӷ�ˢ�ɺ�ɫ�ĳɱ����ѣ�costs[1][2] ��ʾ�� 1 �ŷ��ӷ�ˢ����ɫ�Ļ��ѣ��Դ����ơ�
��������ˢ�����з������ٵĻ��ѳɱ���

ʾ�� 1��
����: costs = [[17,2,17],[16,16,5],[14,3,19]]
���: 10
����: �� 0 �ŷ��ӷ�ˢ����ɫ��1 �ŷ��ӷ�ˢ����ɫ��2 �ŷ��ӷ�ˢ����ɫ�����ٻ���: 2 + 5 + 3 = 10��

ʾ�� 2��
����: costs = [[7,6,2]]
���: 2

��ʾ:
costs.length == n
costs[i].length == 3
1 <= n <= 100
1 <= costs[i][j] <= 20

ע�⣺��������վ 256 ����ͬ��https://leetcode-cn.com/problems/paint-house/

*/

// ����¼
class Solution1 {
public:
	int minCost(vector<vector<int>> &costs) {
		int len = costs.size();
		vector<vector<int>> memo(len, vector<int>(3));
		return min(helper(costs, len - 1, 0, memo),
			       min(helper(costs, len - 1, 1, memo),
					   helper(costs, len - 1, 2, memo)));
	}

private:
	int helper(vector<vector<int>> &costs, int i, int color,
		vector<vector<int>> &memo) {
		if (i < 0) return 0;
		if (memo[i][color] != 0) return memo[i][color];
		memo[i][color] = min(helper(costs, i - 1, (color + 1) % 3, memo),
			                 helper(costs, i - 1, (color + 2) % 3, memo)) +
			             costs[i][color];
		return memo[i][color];
	}
};

// �Ե׶��϶�̬�滮
class Solution2 {
public:
	int minCost(vector<vector<int>> &costs) {
		vector<int> dp(3);
		int len = costs.size();
		for (int j = 0; j < 3; ++j) dp[j] = costs[0][j];
		for (int i = 1; i < len; ++i) {
			vector<int> tmp(3);
			for (int j = 0; j < 3; ++j) {
				tmp[j] = min(dp[(j + 1) % 3], dp[(j + 2) % 3]) + costs[i][j];
			}
			dp = tmp;
		}
		return *min_element(dp.begin(), dp.end());
	}
};