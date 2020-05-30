#include "header.h"

/*

һֻ����һ�ο�������1��̨�ף�Ҳ��������2����
�����������һ��n����̨���ܹ��ж������������Ⱥ����ͬ�㲻ͬ�Ľ������

*/

class Solution1 {
public:
	int jumpFloor(int number)
	{
		if (number == 0) return 0;
		if (number == 1) return 1;
		vector<int> dp(number + 1, 0);
		dp[1] = 1;
		dp[2] = 2;
		int num = 3;
		while (num <= number)
		{
			dp[num] = dp[num - 1] + dp[num - 2];
			num += 1;
		}
		return dp[number];
	}
};

/*

һֻ����һ�ο�������1��̨�ף�Ҳ��������2��������Ҳ��������n����
�����������һ��n����̨���ܹ��ж�����������

*/

class Solution2 {
public:
	int jumpFloorII(int number)
	{
		if (number == 0) return 0;
		if (number == 1) return 1;
		vector<int> dp(number + 1, 0);
		dp[1] = 1;
		int num = 2;
		while (num <= number)
		{
			for (int i = 1; i < num; ++i)
				dp[num] += dp[i];
			dp[num] += 1;
			num += 1;
		}
		return dp[number];
	}
};