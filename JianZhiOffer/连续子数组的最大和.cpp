#include "header.h"

/*

�ڹ��ϵ�һάģʽʶ����,������Ҫ��������������������,������ȫΪ������ʱ��,����ܺý����
����,��������а�������,�Ƿ�Ӧ�ð���ĳ������,�������Աߵ��������ֲ����أ�
����:{6,-3,-2,7,-15,1,2,2},����������������Ϊ8(�ӵ�0����ʼ,����3��Ϊֹ)��
��һ�����飬��������������������еĺ�(�������ĳ���������1)

*/

class Solution {
public:
	int FindGreatestSumOfSubArray(vector<int> array)
	{
		if (array.empty())
			return 0;
		int sum = 0;
		int maxsum = INT_MIN;
		int len = array.size();
		for (int i = 0; i < len; ++i)
		{
			sum += array[i];
			maxsum = max(maxsum, sum);
			if (sum < 0)
				sum = 0;
		}
		return maxsum;
	}
};