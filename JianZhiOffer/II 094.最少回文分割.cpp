#include "header.h"

/*

��ָ Offer II 094.���ٻ��ķָ�

����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����ǻ��ġ����ط���Ҫ������ٷָ���� ��

ʾ�� 1��
���룺s = "aab"
�����1
���ͣ�ֻ��һ�ηָ�Ϳɽ� s �ָ�� ["aa","b"] �������������Ӵ���

ʾ�� 2��
���룺s = "a"
�����0

ʾ�� 3��
���룺s = "ab"
�����1

��ʾ��
1 <= s.length <= 2000
s ����СдӢ����ĸ���

ע�⣺��������վ 132 ����ͬ�� https://leetcode-cn.com/problems/palindrome-partitioning-ii/

*/

// ����¼
class Solution1 {
public:
	int minCut(string s) {
		int len = s.size();
		vector<vector<char>> isPal(len, vector<char>(len, false));
		for (int palLen = 1; palLen <= len; ++palLen) {
			for (int i = 0; i <= len - palLen; ++i) {
				int j = i + palLen - 1;
				isPal[i][j] = (s[i] == s[j] && (palLen < 3 || isPal[i + 1][j - 1]));
			}
		}
		vector<int> memo(len, -1);
		return helper(s, len - 1, isPal, memo);
	}

private:
	int helper(string &s, int end, vector<vector<char>> &isPal, vector<int> &memo) {
		if (memo[end] != -1) return memo[end];
		int len = s.size();
		if (isPal[0][end]) return 0;
		int minNum = INT_MAX;
		for (int i = end; i >= 0; --i) {
			if (isPal[i][end]) minNum = min(minNum, 1 + helper(s, i - 1, isPal, memo));
		}
		return memo[end] = minNum;
	}
};

// �Ե׶��ϵĶ�̬�滮
class Solution2 {
public:
	int minCut(string s) {
		int len = s.size();
		vector<vector<char>> isPal(len, vector<char>(len, false));
		for (int palLen = 1; palLen <= len; ++palLen) {
			for (int i = 0; i <= len - palLen; ++i) {
				int j = i + palLen - 1;
				isPal[i][j] = (s[i] == s[j] && (palLen < 3 || isPal[i + 1][j - 1]));
			}
		}
		vector<int> dp(len + 1, -1);
		for (int i = 0; i < len; ++i) {
			int minNum = INT_MAX;
			for (int j = 0; j <= i; ++j) {
				if (isPal[j][i]) minNum = min(minNum, dp[j] + 1);
			}
			dp[i + 1] = minNum;
		}
		return dp[len];
	}
};
