#include "header.h"

/*

LCR 019. ��֤���Ĵ� II

����һ���ַ���s�������Դ���ɾ��һ���ַ���

�����ж� s �Ƿ��ܳ�Ϊ�����ַ���������ܣ����� true�����򣬷��� false

ʾ�� 1��
���룺s = "aba"
�����true

ʾ�� 2��
���룺s = "abca"
�����true
���ͣ������ɾ���ַ� 'c'

ʾ�� 3��
���룺s = "abc"
�����false

��ʾ��
1 <= s.length <= 10^5
s ��СдӢ����ĸ���

ע�⣺��������վ 680 ����ͬ��https://leetcode-cn.com/problems/valid-palindrome-ii/

*/

class Solution {
public:
	bool validPalindrome(string s) {
		int len = s.size();
		int left = 0, right = len - 1;
		while (left < right && s[left] == s[right]) {
			++left;
			--right;
		}
		return checkPal(s, left + 1, right) || checkPal(s, left, right - 1);
	}

private:
	bool checkPal(const string &s, int left, int right) {
		while (left < right) {
			if (s[left] != s[right]) return false;
			++left;
			--right;
		}
		return true;
	}
};
