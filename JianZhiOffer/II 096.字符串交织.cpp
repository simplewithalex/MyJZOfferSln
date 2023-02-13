#include "header.h"

/*

��ָ Offer II 096. �ַ�����֯

���������ַ��� s1��s2��s3�������æ��֤ s3 �Ƿ����� s1 �� s2 ������ɵġ�

�����ַ��� s �� t ����Ķ�����������£�����ÿ���ַ������ᱻ�ָ�����ɷǿ����ַ�����
s = s1 + s2 + ... + sn
t = t1 + t2 + ... + tm
|n - m| <= 1
���� �� s1 + t1 + s2 + t2 + s3 + t3 + ... ���� t1 + s1 + t2 + s2 + t3 + s3 + ...
ע�⣺a + b ��ζ���ַ��� a �� b ���ӡ�

ʾ�� 1��
���룺s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
�����true

ʾ�� 2��
���룺s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
�����false

ʾ�� 3��
���룺s1 = "", s2 = "", s3 = ""
�����true

��ʾ��
0 <= s1.length, s2.length <= 100
0 <= s3.length <= 200
s1��s2���� s3 ����СдӢ����ĸ���

���ף����ܷ��ʹ�� O(s2.length) ������ڴ�ռ��������?

ע�⣺��������վ 97 ����ͬ�� https://leetcode-cn.com/problems/interleaving-string/

*/


// ����¼
class Solution1 {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
		if (len1 + len2 != len3) return false;
		vector<vector<char>> memo(len1 + 1, vector<char>(len2 + 1, -1));
		return helper(s1, len1, s2, len2, s3, len3, memo);
	}

private:
	bool helper(string &s1, int i, string &s2, int j, string &s3, int k,
		        vector<vector<char>> &memo) {
		if (i == 0) return s2.substr(0, j) == s3.substr(0, k);
		if (j == 0) return s1.substr(0, i) == s3.substr(0, k);
		if (memo[i][j] != -1) return memo[i][j];
		memo[i][j] = (s1[i - 1] == s3[k - 1] && helper(s1, i - 1, s2, j, s3, k - 1, memo)) ||
			         (s2[j - 1] == s3[k - 1] && helper(s1, i, s2, j - 1, s3, k - 1, memo));
		return memo[i][j];
	}
};

// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
		if (len3 != len1 + len2) return false;
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, false));
		for (int i = 0; i <= len1; ++i) {
			for (int j = 0; j <= len2; ++j) {
				if (i == 0 && j == 0) dp[i][j] = true;
				else if (i == 0) dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
				else if (j == 0) dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
				else dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
					            (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
			}
		}
		return dp[len1][len2];
	}
};

// https://leetcode.cn/problems/interleaving-string/solutions/335373/jiao-cuo-zi-fu-chuan-by-leetcode-solution/
// @author ���۹ٷ����