#include "header.h"

/*

����һ����������������һ������S���������в�����������
ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S������������ĳ˻���С�ġ�

*/

class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum)
	{
		int len = array.size();
		if (len < 2) return{};
		vector<int> res;
		int ahead = 0, behind = len - 1;
		while (ahead < behind)
		{
			int temp = array[ahead] + array[behind];
			if (temp == sum)
			{
				res.push_back(array[ahead]);
				res.push_back(array[behind]);
				break;
			}
			else if (temp < sum)
			{
				++ahead;
			}
			else
			{
				--behind;
			}
		}
		return res;
	}
};