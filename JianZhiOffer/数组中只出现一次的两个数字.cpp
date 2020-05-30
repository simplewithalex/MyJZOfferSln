#include "header.h"

/*

һ�����������������������֮�⣬���������ֶ����������Ρ���д�����ҳ�������ֻ����һ�ε����֡�

*/

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int *num1, int *num2)
	{
		int xorsum = 0;
		for (auto i : data)
			xorsum ^= i;
		int bitflag = 1;
		while (!(bitflag&xorsum))
			bitflag <<= 1;
		for (auto i : data)
		{
			if (i&bitflag)
				(*num1) ^= i;
			else
				(*num2) ^= i;
		}
	}
};