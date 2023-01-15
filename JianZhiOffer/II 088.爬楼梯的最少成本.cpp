#include "header.h"

/*

��ָ Offer II 088. ��¥�ݵ����ٳɱ�

����һ���������� cost������ cost[i] �Ǵ�¥�ݵ� i ��̨����������Ҫ֧���ķ��á�һ����֧���˷��ã�����ѡ��������һ����������̨�ס�
�����ѡ����±�Ϊ 0 ���±�Ϊ 1 ��̨�׿�ʼ��¥�ݡ�
������㲢���شﵽ¥�ݶ�������ͻ��ѡ�

ʾ�� 1��
���룺cost = [10,15,20]
�����15
���ͣ��㽫���±�Ϊ 1 ��̨�׿�ʼ��
- ֧�� 15 ������������̨�ף�����¥�ݶ�����
�ܻ���Ϊ 15 ��

ʾ�� 2��
���룺cost = [1,100,1,1,1,100,1,1,100,1]
�����6
���ͣ��㽫���±�Ϊ 0 ��̨�׿�ʼ��
- ֧�� 1 ������������̨�ף������±�Ϊ 2 ��̨�ס�
- ֧�� 1 ������������̨�ף������±�Ϊ 4 ��̨�ס�
- ֧�� 1 ������������̨�ף������±�Ϊ 6 ��̨�ס�
- ֧�� 1 ��������һ��̨�ף������±�Ϊ 7 ��̨�ס�
- ֧�� 1 ������������̨�ף������±�Ϊ 9 ��̨�ס�
- ֧�� 1 ��������һ��̨�ף�����¥�ݶ�����
�ܻ���Ϊ 6 ��

��ʾ��
2 <= cost.length <= 1000
0 <= cost[i] <= 999

ע�⣺��������վ 746 ����ͬ�� https://leetcode-cn.com/problems/min-cost-climbing-stairs/

*/

// ����¼
class Solution1 {
public:
	int minCostClimbingStairs(vector<int> &cost) {
		int len = cost.size();
		vector<int> memo(len);
		return min(helper(cost, len - 1, memo), helper(cost, len - 2, memo));
	}

private:
	int helper(vector<int> &cost, int n, vector<int> &memo) {
		if (n == 0 || n == 1) return cost[n];
		if (memo[n] != 0) return memo[n];
		return memo[n] = min(helper(cost, n - 1, memo), helper(cost, n - 2, memo)) + cost[n];
	}
};

// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int minCostClimbingStairs(vector<int> &cost) {
		int len = cost.size();
		vector<int> dp(len);
		dp[0] = cost[0], dp[1] = cost[1];
		for (int i = 2; i < len; ++i) dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
		return min(dp[len - 1], dp[len - 2]);
	}
};

// �Ż��ռ临�Ӷ�
class Solution3 {
public:
	int minCostClimbingStairs(vector<int> &cost) {
		int len = cost.size();
		int first = cost[0];
		int second = cost[1];
		for (int i = 2; i < len; ++i) {
			int cur = min(first, second) + cost[i];
			first = second;
			second = cur;
		}
		return min(first, second);
	}
};