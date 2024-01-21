#include "header.h"

/*

LCR 070. ���������еĵ�һԪ��

����һ������������ɵ��������飬����ÿ��Ԫ�ض���������Σ�Ψ��һ����ֻ�����һ��
�����ҳ�������ֻ����һ�ε��Ǹ���

����ƵĽ�������������� O(log n) ʱ�临�ӶȺ� O(1) �ռ临�Ӷ�

ʾ�� 1:
����: nums = [1,1,2,3,3,4,4,8,8]
���: 2

ʾ�� 2:
����: nums =  [3,3,7,7,10,11,11]
���: 10

��ʾ:
1 <= nums.length <= 10^5
0 <= nums[i] <= 10^5

ע�⣺��������վ 540 ����ͬ��https://leetcode-cn.com/problems/single-element-in-a-sorted-array/

*/

class Solution1 {
public:
	int singleNonDuplicate(vector<int> &nums) {
		int len = nums.size();
		int lo = 0, hi = len - 1;
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			if (mi & 1) {
				if (mi - 1 >= 0 && nums[mi - 1] == nums[mi]) lo = mi + 1;
				else hi = mi;
			} else {
				if (mi + 1 < len && nums[mi] == nums[mi + 1]) lo = mi + 1;
				else hi = mi;
			}
		}
		return nums[lo];
	}
};


class Solution2 {
public:
	int singleNonDuplicate(vector<int> &nums) {
		int len = nums.size();
		int lo = 0, hi = len - 1;
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			nums[mi] == nums[mi ^ 1] ? lo = mi + 1 : hi = mi;
		}
		return nums[lo];
	}
};

