#include "header.h"

/*

��ָ Offer II 097. �����е���Ŀ

����һ���ַ��� s ��һ���ַ��� t �������� s ���������� t ���ֵĸ�����
�ַ�����һ����������ָ��ͨ��ɾ��һЩ��Ҳ���Բ�ɾ�����ַ��Ҳ�����ʣ���ַ����λ������ɵ����ַ����������磬"ACE" �� "ABCDE" ��һ�������У��� "AEC" ���ǣ�
��Ŀ���ݱ�֤�𰸷��� 32 λ������������Χ��

ʾ�� 1��
���룺s = "rabbbit", t = "rabbit"
�����3
���ͣ�
����ͼ��ʾ, �� 3 �ֿ��Դ� s �еõ� "rabbit" �ķ�����

ʾ�� 2��
���룺s = "babgbag", t = "bag"
�����5
���ͣ�
����ͼ��ʾ, �� 5 �ֿ��Դ� s �еõ� "bag" �ķ�����

��ʾ��
0 <= s.length, t.length <= 1000
s �� t ��Ӣ����ĸ���

ע�⣺��������վ 115 ����ͬ�� https://leetcode-cn.com/problems/distinct-subsequences/

*/

// ����¼
class Solution1 {
public:
	int numDistinct(string s, string t) {
		int sLen = s.size(), tLen = t.size();
		vector<vector<int>> memo(sLen + 1, vector<int>(tLen + 1, -1));
		return helper(s, sLen, t, tLen, memo);
	}

private:
	int helper(string &s, int i, string &t, int j, vector<vector<int>> &memo) {
		if (j == 0) return 1;
		if (i == 0) return 0;
		if (memo[i][j] != -1) return memo[i][j];
		int count = 0;
		if (s[i - 1] == t[j - 1]) {
			count = helper(s, i - 1, t, j, memo) + helper(s, i - 1, t, j - 1, memo);
		} else {
			count = helper(s, i - 1, t, j, memo);
		}
		return memo[i][j] = count;
	}
};

// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int numDistinct(string s, string t) {
		int sLen = s.size(), tLen = t.size();
		vector<vector<unsigned int>> dp(sLen + 1, vector<unsigned int>(tLen + 1));
		for (int i = 0; i <= sLen; ++i) {
			for (int j = 0; j <= tLen; ++j) {
				if (j == 0) {
					dp[i][j] = 1;
				} else if (i == 0) {
					dp[i][j] = 0;
				} else {
					// ���������м������ܳ���int��С
					// �Ե׶��ϼ��㣬���ַ����д����������
					if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
					else dp[i][j] = dp[i - 1][j];
				}
			}
		}
		return dp[sLen][tLen];
	}
};

// https://leetcode.cn/problems/distinct-subsequences/solutions/661537/shou-hua-tu-jie-xiang-jie-liang-chong-ji-4r2y/
// @author https://leetcode.cn/u/xiao_ben_zhu/