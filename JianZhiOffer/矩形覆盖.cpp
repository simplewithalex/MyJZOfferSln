#include "header.h"

/*

���ǿ�����2*1��С���κ��Ż�������ȥ���Ǹ���ľ��Ρ�
������n��2*1��С�������ص��ظ���һ��2*n�Ĵ���Σ��ܹ��ж����ַ�����

*/

class Solution {
public:
	int rectCover(int number)
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