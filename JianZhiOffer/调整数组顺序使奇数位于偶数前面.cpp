#include "header.h"

/*

����һ���������飬ʵ��һ�����������������������ֵ�˳��
ʹ�����е�����λ�������ǰ�벿�֣����е�ż��λ������ĺ�벿�֣�
����֤������������ż����ż��֮������λ�ò��䡣

*/

class Solution {
public:
	void reOrderArray(vector<int> &array)
	{
		if (array.empty())
			return;
		int indexOfEven = 0, indexOfOdd = 0;
		while (indexOfEven < array.size())
		{
			while (indexOfEven < array.size() && (array[indexOfEven] & 1))
				++indexOfEven;
			indexOfOdd = indexOfEven + 1;
			while (indexOfOdd < array.size() && !(array[indexOfOdd] & 1))
			{
				++indexOfOdd;
			}
			if (indexOfOdd < array.size())
			{
				int temp = array[indexOfOdd];
				for (int i = indexOfOdd - 1; i >= indexOfEven; --i)
				{
					array[i + 1] = array[i];
				}
				array[indexOfEven++] = temp;
			}
			else
			{
				break;
			}
		}
	}
};