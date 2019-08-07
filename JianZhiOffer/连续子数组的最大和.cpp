#include "header.h"

/*

�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��һ�����飬��������������������еĺ�(�������ĳ���������1)

*/

class Solution
{
public:
	int FindGreatestSumOfSubArray(vector<int> array)
	{
		if (array.empty()) return 0;
		int maxnum = array[0];
		int temp = maxnum;
		int len = array.size();
		for (int i = 1; i < len; ++i)
		{
			temp += array[i];
			maxnum = max(maxnum, temp);
			if (temp<0)
				temp = 0;
		}
		return maxnum;
	}
};