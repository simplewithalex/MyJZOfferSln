#include "header.h"

/*

���������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ����Ϊ��ջ�ĵ���˳��
����ѹ��ջ���������־�����ȡ���������1,2,3,4,5��ĳջ��ѹ��˳������4,5,3,2,1�Ǹ�ѹջ���ж�Ӧ��һ���������У���4,3,5,1,2�Ͳ������Ǹ�ѹջ���еĵ������С�
��ע�⣺���������еĳ�������ȵ�)

*/

class Solution {
public:
	bool IsPopOrder(vector<int> pushV, vector<int> popV)
	{
		int len1 = pushV.size();
		int len2 = popV.size();
		if (len1 != len2) return false;
		stack<int> s;
		s.push(pushV[0]);
		int i = 0, j = 0;
		while (i<len1)
		{
			if (s.top() != popV[j])
			{
				++i;
				if (i == len1)
					return false;
				s.push(pushV[i]);
			}
			else
			{
				s.pop();
				++j;
				if (j == len2)
					return true;
			}
		}
		return false;
	}
};
