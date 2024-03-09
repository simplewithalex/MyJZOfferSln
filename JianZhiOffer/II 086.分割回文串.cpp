#include "header.h"

/*

LCR 086. �ָ���Ĵ�

����һ���ַ��� s�����㽫 s �ָ��һЩ�Ӵ���ʹÿ���Ӵ����� ���Ĵ�
���� s ���п��ܵķָ��

���Ĵ� �����Ŷ��ͷ��Ŷ���һ�����ַ���

ʾ�� 1��
���룺s = "aab"
�����[["a","a","b"],["aa","b"]]

ʾ�� 2��
���룺s = "a"
�����[["a"]]

��ʾ��
1 <= s.length <= 16
s ����СдӢ����ĸ���

ע�⣺��������վ 131 ����ͬ�� https://leetcode-cn.com/problems/palindrome-partitioning/

*/

// ����Ŀ��ֱ�Ӳο� LeetCode 131 ���ύ
class Solution {
private:
	vector<vector<char>> isPal;
	vector<vector<string>> res;
	vector<string> path;

public:
	vector<vector<string>> partition(string s) {
		int len = s.size();
		isPal.resize(len, vector<char>(len, false));
		for (int palLen = 1; palLen <= len; ++palLen) {
			for (int i = 0; i <= len - palLen; ++i) {
				int j = i + palLen - 1;
				isPal[i][j] =
					(s[i] == s[j] && (palLen < 3 || isPal[i + 1][j - 1]));
			}
		}
		backtrack(s, 0);
		return res;
	}

private:
	void backtrack(const string &s, int idx) {
		if (idx == s.size()) {
			res.push_back(path);
			return;
		}
		for (int j = idx; j < s.size(); ++j) {
			if (isPal[idx][j]) {
				path.push_back(s.substr(idx, j - idx + 1));
				backtrack(s, j + 1);
				path.pop_back();
			}
		}
	}
};
