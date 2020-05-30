#include "header.h"

/*

��С������Χ��һ����Ȧ��Ȼ��,���ָ��һ����m,�ñ��Ϊ0��С���ѿ�ʼ������
ÿ�κ���m-1���Ǹ�С����Ҫ���г��׸�,Ȼ���������Ʒ�����������ѡ����,
���Ҳ��ٻص�Ȧ��,��������һ��С���ѿ�ʼ,����0...m-1����....������ȥ....ֱ��ʣ�����һ��С����,
���Բ��ñ���,������������,�ĸ�С���ѻ������һ���أ�(ע��С���ѵı���Ǵ�0��n-1)

*/

class Solution {
public:
	int LastRemaining_Solution(int n, int m)
	{
		if (n == 0 || m == 0) return -1;
		queue<int> q;
		for (int i = 0; i < n; ++i)
			q.push(i);
		int len = q.size();
		while (len != 1)
		{
			int temp = m - 1;
			while (temp != 0)
			{
				int num = q.front();
				q.pop();
				q.push(num);
				--temp;
			}
			q.pop();
			len = q.size();
		}
		return q.front();
	}
};