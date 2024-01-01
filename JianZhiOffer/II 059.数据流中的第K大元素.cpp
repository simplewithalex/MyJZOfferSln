#include "header.h"

/*

LCR 059. �������еĵ� K ��Ԫ��

���һ���ҵ��������е� k ��Ԫ�ص��ࣨclass��
ע���������ĵ� k ��Ԫ�أ����ǵ� k ����ͬ��Ԫ��

��ʵ�� KthLargest �ࣺ
KthLargest(int k, int[] nums) ʹ������ k �������� nums ��ʼ������
int add(int val) �� val ���������� nums �󣬷��ص�ǰ�������е� k ���Ԫ��

ʾ����
���룺
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
�����
[null, 4, 5, 5, 8, 8]
���ͣ�
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

��ʾ��
1 <= k <= 10^4
0 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
-10^4 <= val <= 10^4
������ add ���� 10^4 ��
��Ŀ���ݱ�֤���ڲ��ҵ� k ��Ԫ��ʱ�������������� k ��Ԫ��

ע�⣺��������վ 703 ����ͬ�� https://leetcode-cn.com/problems/kth-largest-element-in-a-stream/

*/

class KthLargest {
private:
	int size;
	priority_queue<int, vector<int>, greater<int>> pq;

public:
	KthLargest(int k, vector<int> &nums) {
		size = k;
		for (const int &n : nums) {
			pq.push(n);
			if (pq.size() > size) pq.pop();
		}
	}

	int add(int val) {
		pq.push(val);
		if (pq.size() > size) pq.pop();
		return pq.top();
	}
};

/**
* Your KthLargest object will be instantiated and called as such:
* KthLargest* obj = new KthLargest(k, nums);
* int param_1 = obj->add(val);
*/

