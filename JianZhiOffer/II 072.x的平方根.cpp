#include "header.h"

/*

LCR 072. x ��ƽ����

����һ���Ǹ����� x�����㲢���� x �� ����ƽ����
���ڷ������������������ֻ�����������֣�С�����ֽ�����ȥ

ע�⣺������ʹ���κ�����ָ����������������� pow(x, 0.5) ���� x ** 0.5

ʾ�� 1��
���룺x = 4
�����2

ʾ�� 2��
���룺x = 8
�����2
���ͣ�8 ������ƽ������ 2.82842...�����ڷ���������������С�����ֽ�����ȥ

��ʾ��
0 <= x <= 2^31 - 1

ע�⣺��������վ 69 ����ͬ�� https://leetcode-cn.com/problems/sqrtx/

*/

class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1) return x;
		int lo = 1, hi = x / 2;
		while (lo < hi) {
			int mi = lo + (hi - lo + 1) / 2;
			mi > x / mi ? hi = mi - 1 : lo = mi;
		}
		return lo;
	}
};

