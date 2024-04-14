#include "header.h"

/*

LCR 090. ��ҽ��� II

����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݣ�ÿ�䷿�ڶ�����һ�����ֽ�����ط����еķ��ݶ� Χ��һȦ������ζ�ŵ�һ�����ݺ����һ�������ǽ����ŵġ�

ͬʱ�����ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�������ڲ���������װ�õ�����£������ܹ�͵�Ե�����߽�

ʾ�� 1��
���룺nums = [2,3,2]
�����3
���ͣ��㲻����͵�� 1 �ŷ��ݣ���� = 2����Ȼ��͵�� 3 �ŷ��ݣ���� = 2��, ��Ϊ���������ڵ�

ʾ�� 2��
���룺nums = [1,2,3,1]
�����4
���ͣ��������͵�� 1 �ŷ��ݣ���� = 1����Ȼ��͵�� 3 �ŷ��ݣ���� = 3��
͵�Ե�����߽�� = 1 + 3 = 4

ʾ�� 3��
���룺nums = [1,2,3]
�����3

��ʾ��
1 <= nums.length <= 100
0 <= nums[i] <= 1000

ע�⣺��������վ 213 ����ͬ��https://leetcode-cn.com/problems/house-robber-ii/

*/


class Solution1 {
public:
	int rob(vector<int> &nums) {
		int len = nums.size();
		if (len < 2) return nums[0];
		return max(rob1(nums, 1, len - 1), rob1(nums, 2, len));
	}

private:
	// �ӵ�start�����ݿ�ʼ������end�����ݽ���
	int rob1(vector<int> &nums, int start, int end) {
		int len = nums.size();
		vector<int> dp(len + 1);
		dp[start - 1] = 0, dp[start] = nums[start - 1];
		for (int i = start + 1; i <= end; ++i) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}
		return dp[end];
	}
};


class Solution2 {
public:
	int rob(vector<int> &nums) {
		int len = nums.size();
		if (len < 2) return nums[0];
		return max(rob1(nums, 1, len - 1), rob1(nums, 2, len));
	}

private:
	// �ӵ�start�����ݿ�ʼ������end�����ݽ���
	int rob1(vector<int> &nums, int start, int end) {
		int r0 = 0, r1 = nums[start - 1];
		for (int i = start + 1; i <= end; ++i) {
			int new_r = max(r1, r0 + nums[i - 1]);
			r0 = r1;
			r1 = new_r;
		}
		return r1;
	}
};

