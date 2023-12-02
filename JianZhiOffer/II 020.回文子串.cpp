#include "header.h"

/*

����һ���ַ��� s������ͳ�Ʋ���������ַ����л����Ӵ�����Ŀ
�����ַ��� �����Ŷ��͵�������һ�����ַ���
���ַ��� ���ַ����е��������ַ���ɵ�һ������
���в�ͬ��ʼλ�û����λ�õ��Ӵ�����ʹ������ͬ���ַ���ɣ�Ҳ�ᱻ������ͬ���Ӵ�

ʾ�� 1��
���룺s = "abc"
�����3
���ͣ����������Ӵ�: "a", "b", "c"

ʾ�� 2��
���룺s = "aaa"
�����6
���ͣ�6�������Ӵ�: "a", "a", "a", "aa", "aa", "aaa"

��ʾ��
1 <= s.length <= 1000
s ��СдӢ����ĸ���

ע�⣺��������վ 647 ����ͬ: https://leetcode-cn.com/problems/palindromic-substrings/


*/

// ������չ
class Solution1 {
public:
	int countSubstrings(string s) {
		int res = 0;
		int len = s.size();
		for (int i = 0; i < len; ++i) {
			res += extend(s, i, i) + extend(s, i, i + 1);
		}
		return res;
	}

private:
	int extend(const string &s, int i, int j) {
		int cnt = 0;
		for (; i >= 0 && j < s.size(); --i, ++j) {
			if (s[i] != s[j]) break;
			++cnt;
		}
		return cnt;
	}
};

// Manacher
class Solution2 {
public:
	int countSubstrings(string s) {
		string str = preProcess(s);
		int len = str.size();
		vector<int> pal(len);
		int center = 0, maxRight = 0;
		int cnt = 0;
		for (int i = 0; i < len; ++i) {
			if (i < maxRight) {
				int mirror = 2 * center - i;
				pal[i] = min(maxRight - i, pal[mirror]);
			}
			int left = i - (pal[i] + 1);
			int right = i + (pal[i] + 1);
			while (left >= 0 && right < len && str[left] == str[right]) {
				--left;
				++right;
				++pal[i];
			}
			if ((i + pal[i]) > maxRight) {
				maxRight = i + pal[i];
				center = i;
			}
			cnt += (pal[i] + 1) / 2;
		}
		return cnt;
	}

private:
	string preProcess(const string &s) {
		int len = s.size();
		string str;
		for (int i = 0; i < len; ++i) str.append({ '#', s[i] });
		str.append("#");
		return str;
	}
};

// ��̬�滮
class Solution3 {
public:
	int countSubstrings(string s) {
		if (s.empty()) return 0;
		int len = s.size();
		vector<vector<char>> isPal(len, vector<char>(len, false));
		int res = 0;
		for (int palLen = 1; palLen <= len; ++palLen) {
			for (int i = 0; i <= len - palLen; ++i) {
				int j = i + palLen - 1;
				isPal[i][j] = (s[i] == s[j]) &&
					(palLen < 3 || isPal[i + 1][j - 1]);
				if (isPal[i][j]) ++res;
			}
		}
		return res;
	}
};

