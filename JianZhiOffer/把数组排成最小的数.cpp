#include "header.h"

/*

����һ�����������飬����������������ƴ�������ų�һ��������ӡ��ƴ�ӳ���������������С��һ����
������������{3��32��321}�����ӡ���������������ųɵ���С����Ϊ321323��

*/

class Solution {
public:
	string PrintMinNumber(vector<int> numbers)
	{
		if (numbers.empty())
			return{};
		int len = numbers.size();
		string res;
		sort(numbers.begin(), numbers.end(),
			[](const int &str1, const int &str2) -> bool
		{
			string A = to_string(str1) + to_string(str2);
			string B = to_string(str2) + to_string(str1);
			return A < B;
		}
		);
		for (auto i : numbers)
			res += to_string(i);
		return res;
	}
};