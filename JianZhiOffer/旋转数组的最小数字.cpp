#include "header.h"

/*

��һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת�� 
����һ���Ǽ�����������һ����ת�������ת�������СԪ�ء� 
��������{3,4,5,1,2}Ϊ{1,2,3,4,5}��һ����ת�����������СֵΪ1�� 
NOTE������������Ԫ�ض�����0���������СΪ0���뷵��0��

*/

class Solution {
public:
	int minNumberInRotateArray(vector<int> rotateArray)
	{
		int len = rotateArray.size();
		if (len == 0) return 0;
		int lo = 0, hi = len - 1;
		while (lo < hi)
		{
			if (rotateArray[lo] < rotateArray[hi])
				return rotateArray[lo];
			int mi = (hi + lo) >> 1;
			(rotateArray[mi]>rotateArray[hi]) ? lo = mi + 1 : (rotateArray[mi] < rotateArray[hi] ? hi = mi : --hi);
		}
		return rotateArray[lo];
	}
};