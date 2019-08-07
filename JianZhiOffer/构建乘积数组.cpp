#include "header.h"

/*

����һ������A[0,1,...,n-1],�빹��һ������B[0,1,...,n-1],
����B�е�Ԫ��B[i]=A[0]*A[1]*...*A[i-1]*A[i+1]*...*A[n-1]��
����ʹ�ó�����

*/

class Solution {
public:
	vector<int> multiply(const vector<int> &A)
	{
		int len = A.size();
		if (len == 0) return{};
		vector<int> res(len, 1);
		for (int i = 1; i < len; ++i)
		{
			res[i] = res[i - 1] * A[i - 1];
		}
		int mem = 1;
		for (int i = len - 2; i >= 0; --i)
		{
			mem *= A[i + 1];
			res[i] *= mem;
		}
		return res;
	}
};