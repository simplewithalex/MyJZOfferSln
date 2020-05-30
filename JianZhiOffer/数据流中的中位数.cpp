#include "header.h"

/*

������������ж�����������ֵ����ô��λ������������ֵ����֮��λ���м����ֵ��
������������ж���ż������ֵ����ô��λ������������ֵ����֮���м���������ƽ��ֵ��
����ʹ��Insert()������ȡ��������ʹ��GetMedian()������ȡ��ǰ��ȡ���ݵ���λ����

*/

class Solution {
public:
	priority_queue<int, vector<int>, less<int>> maxq;
	priority_queue<int, vector<int>, greater<int>> minq;
	void Insert(int num)
	{
		if ((maxq.size() + minq.size()) & 1)
		{
			if (!minq.empty() && num > minq.top())
			{
				int temp = minq.top();
				minq.pop();
				maxq.push(temp);
				minq.push(num);
			}
			else
			{
				maxq.push(num);
			}
		}
		else
		{
			if (!maxq.empty() && num < maxq.top())
			{
				int temp = maxq.top();
				maxq.pop();
				minq.push(temp);
				maxq.push(num);
			}
			else
			{
				minq.push(num);
			}
		}
	}

	double GetMedian()
	{
		if ((maxq.size() + minq.size()) & 1)
			return minq.top();
		else
			return (maxq.top() + minq.top()) / 2.0;
	}
};