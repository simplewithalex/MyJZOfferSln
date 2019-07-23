#include "header.h"

/*

����һ��double���͵ĸ�����base��int���͵�����exponent��
��base��exponent�η���

*/

class Solution {
public:
	double Power(double base, int exponent)
	{
		double value = 1.0;
		if (exponent > 0)
		{
			while (exponent)
			{
				value *= base;
				--exponent;
			}
		}
		else if (exponent < 0)
		{
			while (exponent)
			{
				value *= base;
				++exponent;
			}
			value = 1 / value;
		}
		return value;
	}
};