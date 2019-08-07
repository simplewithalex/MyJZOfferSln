#include "header.h"

/*

����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ����
����������Yes,�������No���������������������������ֶ�������ͬ��

*/

class Solution {
public:
	bool VerifySquenceOfBST(vector<int> sequence)
	{
		if (sequence.empty())
			return false;
		int len = sequence.size();
		return recur(sequence, 0, len - 1);
	}
	bool recur(vector<int> &sequence, int start, int end)
	{
		int root = sequence[end];
		int i = start;
		for (; i<end; ++i)
		{
			if (sequence[i]>root)
				break;
		}
		int j = i;
		for (; j<end; ++j)
		{
			if (sequence[j]<root)
				return false;
		}

		bool left = true;
		if (i>start)
			left = recur(sequence, start, i - 1);
		bool right = true;
		if (i<end)
			right = recur(sequence, i, end - 1);
		return left&&right;
	}
};