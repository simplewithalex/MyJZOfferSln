#include "header.h"

/*

��һ����ά�����У�ÿ��һά����ĳ�����ͬ����ÿһ�ж����մ����ҵ�����˳������ÿһ�ж����մ��ϵ��µ�����˳������
�����һ������������������һ����ά�����һ���������ж��������Ƿ��и�������

*/

class Solution {
public:
	bool Find(int target, vector<vector<int>> array)
	{
		if (array.empty() || array[0].empty()) return false;
		int rows = array.size(), cols = array[0].size();
		int row = 0, col = cols - 1;
		while (row < rows&&col >= 0)
		{
			if (array[row][col] == target)
				return true;
			else if (array[row][col] < target)
				++row;
			else
				--col;
		}
		return false;
	}
};