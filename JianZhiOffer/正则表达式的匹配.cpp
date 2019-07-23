#include "header.h"

/*

��ʵ��һ����������ƥ�����'.'��'*'��������ʽ��
ģʽ�е��ַ�'.'��ʾ����һ���ַ�����'*'��ʾ��ǰ����ַ����Գ�������Σ�����0�Σ��� 
�ڱ����У�ƥ����ָ�ַ����������ַ�ƥ������ģʽ��
���磬�ַ���"aaa"��ģʽ"a.a"��"ab*ac*a"ƥ�䣬������"aa.a"��"ab*a"����ƥ�䡣

*/


//�ݹ�ķ���
class Solution1 {
public:
	bool match(char *str, char *pattern)
	{
		if (!str || !pattern) return false;
		if (*pattern == '\0'&&*str != '\0') return false;
		if (*str == '\0'&&*pattern == '\0') return true;
		if (*(pattern + 1) != '*')
		{
			if (*str == *pattern || (*str != '\0'&&*pattern == '.'))
			{
				return match(++str, ++pattern);
			}
			else
			{
				return false;
			}
		}
		else
		{
			if (*str == *pattern || (*str != '\0'&&*pattern == '.'))
			{
				return match(str, pattern + 2) || match(++str, pattern);
			}
			else
			{
				return match(str, pattern + 2);
			}
		}
	}
};

//��̬�滮�ķ���
class Solution2 {
public:
	bool match(char *s, char *p)
	{
		if (!s || !p) return false;
		int sLen = strlen(s), pLen = strlen(p);
		vector<vector<bool>> dp(sLen + 1, vector<bool>(pLen + 1, false));
		dp[0][0] = true;
		for (int j = 1; j < dp[0].size(); ++j)
		{
			if (p[j - 1] == '*')
			{
				if (dp[0][j - 2]) dp[0][j] = true;
			}
		}
		for (int i = 1; i < dp.size(); ++i)
		{
			for (int j = 1; j < dp[0].size(); ++j)
			{
				if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
					dp[i][j] = dp[i - 1][j - 1];
				if (p[j - 1] == '*')
				{
					if (s[i - 1] != p[j - 2] && p[j - 2] != '.')
						dp[i][j] = dp[i][j - 2];
					else
						dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
				}
			}
		}
		return dp[sLen][pLen];
	}
};
//https://leetcode.com/problems/regular-expression-matching/discuss/5651/Easy-DP-Java-Solution-with-detailed-Explanation