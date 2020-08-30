#include "header.h"

/*

ͳ��һ�����������������г��ֵĴ�����

ʾ�� 1:
����: nums = [5,7,7,8,8,10], target = 8
���: 2

ʾ�� 2:
����: nums = [5,7,7,8,8,10], target = 6
���: 0

���ƣ�0 <= ���鳤�� <= 50000
ע�⣺��������վ 34 ����ͬ��������ֵ��ͬ����https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/

*/

class Solution {
public:
	int search(vector<int> &nums, int target) 
	{
		if (nums.empty()) return 0;
		int first = lowerBound(nums, target);
		if (first == -1) return 0;
		int second = upBound(nums, target);
		return second - first + 1;
	}
	//�õ���ͬĿ��Ԫ�������һ��
	int lowerBound(vector<int> &nums, int target)
	{
		int len = nums.size();
		int lo = 0, hi = len - 1;
		while (lo < hi)
		{
			int mi = lo + ((hi - lo) >> 1);
			(nums[mi] < target) ? lo = mi + 1 : hi = mi;
		}
		return nums[lo] == target ? lo : -1;
	}
	//�õ���ͬĿ��Ԫ�����ұ�һ��
	int upBound(vector<int> &nums, int target)
	{
		int len = nums.size();
		int lo = 0, hi = len - 1;
		while (lo < hi)
		{
			int mi = lo + ((hi - lo + 1) >> 1);
			(nums[mi] > target) ? hi = mi - 1 : lo = mi;
		}
		return nums[lo] == target ? lo : -1;
	}
};