#include "header.h"

/*

Ҫ������һ������n���������쳲��������еĵ�n���0��ʼ����0��Ϊ0��

*/

class Solution {
public:
	int Fibonacci(int n)
	{
		if (n == 0) return 0;
		int a = 1, b = 0;
		while (--n > 0)
		{
			a = a + b;
			b = a - b;
		}
		return a;
	}
};