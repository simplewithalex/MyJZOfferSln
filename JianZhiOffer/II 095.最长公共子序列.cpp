#include "header.h"

/*

��ָ Offer II 095. �����������

���������ַ��� text1 �� text2�������������ַ����� ����������� �ĳ��ȡ���������ڹ��������У����� 0
һ���ַ����� ������ ��ָ����һ���µ��ַ�����������ԭ�ַ����ڲ��ı��ַ������˳��������ɾ��ĳЩ�ַ���Ҳ���Բ�ɾ���κ��ַ�������ɵ����ַ���
���磬"ace" �� "abcde" �������У��� "aec" ���� "abcde" ��������
�����ַ����� ���������� ���������ַ�������ͬӵ�е�������

ʾ�� 1��
���룺text1 = "abcde", text2 = "ace"
�����3
���ͣ�������������� "ace" �����ĳ���Ϊ 3

ʾ�� 2��
���룺text1 = "abc", text2 = "abc"
�����3
���ͣ�������������� "abc" �����ĳ���Ϊ 3

ʾ�� 3��
���룺text1 = "abc", text2 = "def"
�����0
���ͣ������ַ���û�й��������У����� 0

��ʾ��
1 <= text1.length, text2.length <= 1000
text1 �� text2 ����СдӢ���ַ���ɡ�

ע�⣺��������վ 1143 ����ͬ�� https://leetcode-cn.com/problems/longest-common-subsequence/

*/

// ����¼
class Solution1 {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int len1 = text1.size(), len2 = text2.size();
		vector<vector<int>> memo(len1 + 1, vector<int>(len2 + 1, -1));
		return helper(text1, text2, len1, len2, memo);
	}

private:
	int helper(string &s1, string &s2, int m, int n,
		       vector<vector<int>> &memo) {
		if (m == 0 || n == 0) return 0;
		if (memo[m][n] != -1) return memo[m][n];
		if (s1[m - 1] == s2[n - 1]) memo[m][n] = 1 + helper(s1, s2, m - 1, n - 1, memo);
		else memo[m][n] = max(helper(s1, s2, m - 1, n, memo), helper(s1, s2, m, n - 1, memo));
		return memo[m][n];
	}
};

// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int longestCommonSubsequence(string text1, string text2) {
		int len1 = text1.size(), len2 = text2.size();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 1; i <= len1; ++i) {
			for (int j = 1; j <= len2; ++j) {
				if (text1[i - 1] == text2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
				else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
			}
		}
		return dp[len1][len2];
	}
};