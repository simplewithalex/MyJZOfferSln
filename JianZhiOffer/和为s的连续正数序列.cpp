#include "header.h"

/*

С����ϲ����ѧ,��һ����������ѧ��ҵʱ,Ҫ������9~16�ĺ�,�����Ͼ�д������ȷ����100��
���������������ڴ�,�����뾿���ж������������������еĺ�Ϊ100(���ٰ���������)��
û���,���͵õ���һ������������Ϊ100������:18,19,20,21,22��
���ڰ����⽻����,���ܲ���Ҳ�ܿ���ҳ����к�ΪS��������������?

*/

class Solution {
public:
	vector<vector<int>> FindContinuousSequence(int sum)
	{
		if (sum < 3) return{};
		vector<vector<int>> res;
		int minnum = 1, maxnum = 2, tempsum = 3;
		while (minnum < maxnum)
		{
			if (tempsum == sum)
			{
				vector<int> temp;
				int tempnum = minnum;
				while (tempnum <= maxnum)
					temp.push_back(tempnum++);
				res.push_back(temp);
				++maxnum;
				tempsum += maxnum;
			}
			else if (tempsum < sum)
			{
				++maxnum;
				tempsum += maxnum;
			}
			else
			{
				tempsum -= minnum;
				++minnum;
			}
		}
		return res;
	}
};