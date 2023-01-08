#include "header.h"

/*

��ָ Offer II 076. �����еĵ� k �������

������������ nums ������ k���뷵�������е� k ������Ԫ�ء�
��ע�⣬����Ҫ�ҵ������������ĵ� k ������Ԫ�أ������ǵ� k ����ͬ��Ԫ�ء�
�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣

ʾ�� 1:
����: [3,2,1,5,6,4], k = 2
���: 5

ʾ�� 2:
����: [3,2,3,1,2,4,5,5,6], k = 4
���: 4

��ʾ��
1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4

ע�⣺��������վ 215 ����ͬ�� https://leetcode-cn.com/problems/kth-largest-element-in-an-array/

*/

// ���ٻ���
class Solution1 {
public:
	int findKthLargest(vector<int> &nums, int k) {
		int len = nums.size();
		int lo = 0, hi = len - 1;
		int target = len - k;
		int index = partition(nums, lo, hi);
		while (index != target) {
			if (index > target) {
				hi = index - 1;
				index = partition(nums, lo, hi);
			}
			else {
				lo = index + 1;
				index = partition(nums, lo, hi);
			}
		}
		return nums[index];
	}

private:
	int partition(vector<int> &nums, int lo, int hi) {
		swap(nums[lo], nums[lo + rand() % (hi - lo + 1)]);
		int pivot = nums[lo];
		while (lo < hi) {
			while (lo < hi) {
				if (nums[hi] > pivot) {
					--hi;
				} else {
					nums[lo++] = nums[hi];
					break;
				}
			}
			while (lo < hi) {
				if (nums[lo] < pivot) {
					++lo;
				} else {
					nums[hi--] = nums[lo];
					break;
				}
			}
		}
		nums[lo] = pivot;
		return lo;
	}
};


// ������
class Solution2 {
public:
	int findKthLargest(vector<int> &nums, int k) {
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int num : nums) {
			pq.push(num);
			if (pq.size() > k) pq.pop();
		}
		return pq.top();
	}
};