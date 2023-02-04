#include "header.h"

/*

��ָ Offer II 092. ��ת�ַ�

���һ���������ַ���������һЩ 0������û�� 0���������һЩ 1��Ҳ����û�� 1������ʽ��ɵģ���ô���ַ����ǵ���������
����һ���������ַ��� s������Խ��κ� 0 ��תΪ 1 ���߽� 1 ��תΪ 0
����ʹ s ������������С��ת������

ʾ�� 1��
���룺s = "00110"
�����1
���ͣ���ת���һλ�õ� 00111

ʾ�� 2��
���룺s = "010110"
�����2
���ͣ���ת�õ� 011111�������� 000111

ʾ�� 3��
���룺s = "00011000"
�����2
���ͣ���ת�õ� 00000000

��ʾ��
1 <= s.length <= 10^5
s[i] Ϊ '0' �� '1'

ע�⣺��������վ 926 ����ͬ�� https://leetcode-cn.com/problems/flip-string-to-monotone-increasing/


*/

// ����¼
class Solution1 {
public:
	int minFlipsMonoIncr(string s) {
		int len = s.size();
		vector<vector<int>> memo(len + 1, vector<int>(2, -1));
		return min(helper(s, len, '0', memo), helper(s, len, '1', memo));
	}

private:
	int helper(string &s, int idx, char c, vector<vector<int>> &memo) {
		if (idx == 0) return 0;
		if (memo[idx][c - '0'] != -1) return memo[idx][c - '0'];
		if (c == '0') {
			return memo[idx][c - '0'] = helper(s, idx - 1, '0', memo) + (s[idx - 1] == '1');
		} else {
			return memo[idx][c - '0'] = min(helper(s, idx - 1, '0', memo),
				                            helper(s, idx - 1, '1', memo)) + (s[idx - 1] == '0');
		}
	}
};

// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int minFlipsMonoIncr(string s) {
		int len = s.size();
		vector<vector<int>> dp(len, vector<int>(2, 0));
		dp[0][0] = s[0] == '1' ? 1 : 0;
		dp[0][1] = s[0] == '0' ? 1 : 0;
		for (int i = 1; i < len; ++i) {
			dp[i][0] = dp[i - 1][0] + (s[i] == '1' ? 1 : 0);
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + (s[i] == '0' ? 1 : 0);
		}
		return min(dp[len - 1][0], dp[len - 1][1]);
	}
};

// https://leetcode.cn/problems/flip-string-to-monotone-increasing/solutions/1592230/jiang-zi-fu-chuan-fan-zhuan-dao-dan-diao-stjd 
// @author ���۹ٷ����

