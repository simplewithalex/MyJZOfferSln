#include "header.h"

/*

����һ������������ nums���ҵ�������ͬ������ 0 �� 1 ������������飬�����ظ�������ĳ���

ʾ�� 1:
����: nums = [0,1]
���: 2
˵��: [0, 1] �Ǿ�����ͬ���� 0 �� 1 ������������顣

ʾ�� 2:
����: nums = [0,1,0]
���: 2
˵��: [0, 1] (�� [1, 0]) �Ǿ�����ͬ����0��1������������顣

��ʾ��
1 <= nums.length <= 10^5
nums[i] ���� 0 ���� 1

ע�⣺��������վ 525 ����ͬ�� https://leetcode-cn.com/problems/contiguous-array/

*/

class Solution {
public:
	int findMaxLength(vector<int> &nums) {
		unordered_map<int, int> m = { { 0, -1 } };
		int res = 0, cur = 0;
		for (int i = 0; i < nums.size(); ++i) {
			nums[i] == 0 ? --cur : ++cur;
			if (m.count(cur)) res = max(res, i - m[cur]);
			else m[cur] = i;
		}
		return res;
	}
};

