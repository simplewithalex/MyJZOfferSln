#include "header.h"

/*

����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ��������СԪ�ص�min������ʱ�临�Ӷ�ӦΪO��1������

*/

class Solution {
public:
	stack<int> s;
	stack<int> mins;
	void push(int value)
	{
		s.push(value);
		if (!mins.empty())
		{
			if (value < mins.top())
				mins.push(value);
			else
				mins.push(mins.top());
		}
		else
		{
			mins.push(value);
		}
	}
	void pop()
	{
		if (!s.empty() && !mins.empty())
		{
			s.pop();
			mins.pop();
		}
	}
	int top()
	{
		if (!s.empty())
			return s.top();
		else
			return 0;
	}
	int min()
	{
		if (!mins.empty())
			return mins.top();
		else
			return 0;
	}
};