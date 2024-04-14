#include "header.h"

/*

LCR 089. ��ҽ���

����һ��רҵ��С͵���ƻ�͵���ؽֵķ��ݡ�

ÿ�䷿�ڶ�����һ�����ֽ�Ӱ����͵�Ե�Ψһ��Լ���ؾ������ڵķ���װ���໥��ͨ�ķ���ϵͳ������������ڵķ�����ͬһ���ϱ�С͵���룬ϵͳ���Զ�������

����һ������ÿ�����ݴ�Ž��ķǸ��������飬�����㲻��������װ�õ�����£�һҹ֮���ܹ�͵�Ե�����߽�


ʾ�� 1��
���룺[1,2,3,1]
�����4
���ͣ�͵�� 1 �ŷ��� (��� = 1) ��Ȼ��͵�� 3 �ŷ��� (��� = 3)��
͵�Ե�����߽�� = 1 + 3 = 4

ʾ�� 2��
���룺[2,7,9,3,1]
�����12
���ͣ�͵�� 1 �ŷ��� (��� = 2), ͵�� 3 �ŷ��� (��� = 9)������͵�� 5 �ŷ��� (��� = 1)��
͵�Ե�����߽�� = 2 + 9 + 1 = 12

��ʾ��
1 <= nums.length <= 100
0 <= nums[i] <= 400

ע�⣺��������վ 198 ����ͬ�� https://leetcode-cn.com/problems/house-robber/

*/

// ����¼
class Solution1 {
private:
	vector<int> memo;

public:
	int rob(vector<int> &nums) {
		int len = nums.size();
		memo.resize(len + 1, -1);
		return helper(nums, len);
	}

private:
	int helper(vector<int> &nums, int idx) {
		if (idx <= 0) return 0;
		if (memo[idx] != -1) return memo[idx];
		return memo[idx] = max(helper(nums, idx - 1),
			                   helper(nums, idx - 2) + nums[idx - 1]);
	}
};


// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int rob(vector<int> &nums) {
		int len = nums.size();
		vector<int> dp(len + 1);
		dp[0] = 0, dp[1] = nums[0];
		for (int i = 2; i <= len; ++i) {
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}
		return dp[len];
	}
};

// �ռ��Ż�
class Solution3 {
public:
	int rob(vector<int> &nums) {
		int r0 = 0, r1 = 0;
		for (int num : nums) {
			int new_r = max(r1, r0 + num);
			r0 = r1;
			r1 = new_r;
		}
		return r1;
	}
};
