#include "header.h"

/*

����һ������ͻ������ڵĴ�С���ҳ����л�����������ֵ�����ֵ��
���磬�����������{2,3,4,2,6,2,5,1}���������ڵĴ�С3��
��ôһ������6���������ڣ����ǵ����ֵ�ֱ�Ϊ{4,4,6,6,6,5}��

*/

class Solution {
public:
	vector<int> maxInWindows(const vector<int> &num, unsigned int size)
	{
		int len = num.size();
		if (len < size || size < 1) return{};
		vector<int> res;
		deque<int> de;
		for (int i = 0; i < size; ++i)
		{
			while (!de.empty() && num[i] > num[de.back()])
				de.pop_back();
			de.push_back(i);
		}
		res.push_back(num[de.front()]);
		for (int i = size; i < len; ++i)
		{
			while (!de.empty() && num[i] > num[de.back()])
				de.pop_back();
			if (!de.empty() && de.front() == i - size)
				de.pop_front();
			de.push_back(i);
			res.push_back(num[de.front()]);
		}
		return res;
	}
};