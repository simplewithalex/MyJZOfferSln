#include "header.h"

/*

��ֻ����������2��3��5��������������Ugly Number����
����6��8���ǳ�������14���ǣ���Ϊ������������7�� 
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������

*/

class Solution {
public:
	int GetUglyNumber_Solution(int index)
	{
		if (index == 0) return 0;
		vector<int> ugly(index, 0);
		ugly[0] = 1;
		int m2 = 0, m3 = 0, m5 = 0;
		for (int i = 1; i < index; ++i)
		{
			ugly[i] = minOfnum(ugly[m2] * 2, ugly[m3] * 3, ugly[m5] * 5);
			while (ugly[m2] * 2 <= ugly[i])
				++m2;
			while (ugly[m3] * 3 <= ugly[i])
				++m3;
			while (ugly[m5] * 5 <= ugly[i])
				++m5;
		}
		return ugly[index - 1];
	}
	int minOfnum(int a, int b, int c)
	{
		int minnum = a < b ? a : b;
		minnum = minnum < c ? minnum : c;
		return minnum;
	}
};