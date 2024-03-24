#include "header.h"

/*

LCR 012. Ѱ������������±�

����һ���������� nums ������������ �����±�
���� �����±� �������һ���±꣬���������Ԫ����ӵĺ͵����Ҳ�����Ԫ����ӵĺ�
��������±�λ����������ˣ���ô�����֮����Ϊ 0����Ϊ���±����಻����Ԫ�ء���һ����������±�λ���������Ҷ�ͬ������
��������ж�������±꣬Ӧ�÷��� ������ ����һ����������鲻���������±꣬���� -1

ʾ�� 1��
���룺nums = [1, 7, 3, 6, 5, 6]
�����3
���ͣ�
�����±��� 3
�����֮�� sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
�Ҳ���֮�� sum = nums[4] + nums[5] = 5 + 6 = 11 ���������

ʾ�� 2��
���룺nums = [1, 2, 3]
�����-1
���ͣ�
�����в���������������������±�

ʾ�� 3��
���룺nums = [2, 1, -1]
�����0
���ͣ�
�����±��� 0
�����֮�� sum = 0�����±� 0 ��಻����Ԫ�أ�
�Ҳ���֮�� sum = nums[1] + nums[2] = 1 + -1 = 0

��ʾ��
1 <= nums.length <= 10^4
-1000 <= nums[i] <= 1000


ע�⣺��������վ 1991 ����ͬ��https://leetcode-cn.com/problems/find-the-middle-index-in-array/

ע�⣺��������վ 724 ����ͬ�� https://leetcode-cn.com/problems/find-pivot-index/


*/

class Solution {
public:
	int pivotIndex(vector<int> &nums) {
		int total = accumulate(nums.begin(), nums.end(), 0);
		int left_sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (left_sum * 2 + nums[i] == total) return i;
			left_sum += nums[i];
		}
		return -1;
	}
};
// https://leetcode.cn/problems/find-pivot-index/solutions/579264/xun-zhao-shu-zu-de-zhong-xin-suo-yin-by-gzjle/
// @author LeetCode�ٷ����
