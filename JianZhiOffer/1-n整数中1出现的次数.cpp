#include "header.h"

/*

�������Ǹ�����������1���ֵĴ�������1 �� n ��1���ֵĴ�������
���磬1~13�а���1��������1��10��11��12��13��˹�����6�Ρ�

*/


class Solution {
public:
	int NumberOf1Between1AndN_Solution(int n)
	{
		int count = 0;
		long long i = 1;
		for (i = 1; i <= n; i *= 10)
		{
			int a = n / i, b = n % i;
			count += (a + 8) / 10 * i + (a % 10 == 1)*(b + 1);
		}
		return count;
	}
};