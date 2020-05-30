#include "header.h"

/*

�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�
����һ������,�����������е�����Ե�����P��

*/

class Solution {
public:
	int InversePairs(vector<int> data)
	{
		if (data.empty()) return 0;
		int count = 0;
		int len = data.size();
		mergrsort(data, 0, len, count);
		return count;
	}
	int mergrsort(vector<int> &data, int lo, int hi, int &count)
	{
		if (hi - lo < 2) return lo;
		int mi = (lo + hi) >> 1;
		int left = 0, right = 0;
		left = mergrsort(data, lo, mi, count);
		right = mergrsort(data, mi, hi, count);
		while (left >= lo&&right >= mi)
		{
			if (data[left]>data[right])
			{
				count += right - mi + 1;
				--left;
			}
			else
			{
				--right;
			}
		}
		merge(data, lo, mi, hi);
		return hi - 1;
	}
	void merge(vector<int> &data, int lo, int mi, int hi)
	{
		int leftnum = mi - lo;
		vector<int> temp(leftnum, 0);
		for (int i = 0, j = lo; i < leftnum; ++i, ++j)
		{
			temp[i] = data[j];
		}
		int i = 0, j = mi, k = lo;
		while (i < leftnum&&j < hi)
		{
			if (temp[i] <= data[j])
				data[k++] = temp[i++];
			else
				data[k++] = data[j++];
		}
		while (i < leftnum)
			data[k++] = temp[i++];
	}
};