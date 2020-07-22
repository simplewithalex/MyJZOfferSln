#include "header.h"

/*


����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ����������λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֡�

ʾ����
���룺nums = [1,2,3,4]
�����[1,3,2,4]
ע��[3,1,2,4] Ҳ����ȷ�Ĵ�֮һ��

��ʾ��
1 <= nums.length <= 50000
1 <= nums[i] <= 10000

*/

//˫ָ��
class Solution {
public:
	vector<int> exchange(vector<int> &nums) 
	{
		if (nums.empty()) return {};
		int len = nums.size();
		int i = 0, j = len - 1;
		while (i < j)
		{
			while (i < j && (nums[i] % 2 == 1)) ++i;
			while (i < j && (nums[j] % 2 == 0)) --j;
			swap(nums[i], nums[j]);
		}
		return nums;
	}
};