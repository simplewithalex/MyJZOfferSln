#include "header.h"

/*

LCR 017. ��С�����Ӵ�

����һ���ַ��� s�� һ���ַ��� t
���� s �к��� t �����ַ�����С�Ӵ������ s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� ""

ע�⣺
���� t ���ظ��ַ�������Ѱ�ҵ����ַ����и��ַ��������벻���� t �и��ַ�����
��� s �д����������Ӵ������Ǳ�֤����Ψһ�Ĵ�

ʾ�� 1��
���룺s = "ADOBECODEBANC", t = "ABC"
�����"BANC"
���ͣ���С�����Ӵ� "BANC" ���������ַ��� t �� 'A'��'B' �� 'C'

ʾ�� 2��
���룺s = "a", t = "a"
�����"a"
���ͣ������ַ��� s ����С�����Ӵ�

ʾ�� 3:
����: s = "a", t = "aa"
���: ""
����: t �������ַ� 'a' ��Ӧ������ s ���Ӵ��У����û�з������������ַ��������ؿ��ַ���

��ʾ��
m == s.length
n == t.length
1 <= m, n <= 10^5
s �� t ��Ӣ����ĸ���

���ף��������һ���� o(m+n) ʱ���ڽ����������㷨��

ע�⣺��������վ 76 �����ƣ�https://leetcode-cn.com/problems/minimum-window-substring/

*/


class Solution {
public:
	string minWindow(string s, string t) {
		vector<int> mp(60);
		for (const auto &c : t) ++mp[c - 'A'];
		int start = 0, end = 0, counter = t.size();
		int sLen = s.size(), minStart = 0, minLen = INT_MAX;
		while (end < sLen) {
			if (mp[s[end] - 'A'] > 0) --counter;
			--mp[s[end] - 'A'];
			++end;
			while (counter == 0) {
				if (end - start < minLen) {
					minStart = start;
					minLen = end - start;
				}
				if (mp[s[start] - 'A'] == 0) ++counter;
				++mp[s[start] - 'A'];
				++start;
			}
		}
		return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
	}
};
// https://leetcode.com/problems/minimum-window-substring/solutions/26808/here-is-a-10-line-template-that-can-solve-most-substring-problems/
// @author https://leetcode.com/zjh08177/

