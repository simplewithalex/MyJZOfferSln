#include "header.h"

/*

дһ������������������֮�ͣ�Ҫ���ں������ڲ���ʹ��+��-��*��/����������š�

*/

class Solution {
public:
	int Add(int num1, int num2)
	{
		int orDiff = num1^num2;
		int And = num1&num2;
		while (And <<= 1)
		{
			int temp = orDiff;
			orDiff ^= And;
			And &= temp;
		}
		return orDiff;
	}
};
