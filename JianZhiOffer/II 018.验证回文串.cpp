#include "header.h"

/*

LCR 018. ��֤���Ĵ�

����ڽ����д�д�ַ�ת��ΪСд�ַ������Ƴ����з���ĸ�����ַ�֮�󣬶������Ŷ��ͷ��Ŷ���һ�����������Ϊ�ö�����һ�����Ĵ�

��ĸ�����ֶ�������ĸ�����ַ�

����һ���ַ��� s��������� ���Ĵ� ������ true�����򣬷��� false

ʾ�� 1��
����: s = "A man, a plan, a canal: Panama"
�����true
���ͣ�"amanaplanacanalpanama" �ǻ��Ĵ�

ʾ�� 2��
���룺s = "race a car"
�����false
���ͣ�"raceacar" ���ǻ��Ĵ�

ʾ�� 3��
���룺s = " "
�����true
���ͣ����Ƴ�����ĸ�����ַ�֮��s ��һ�����ַ��� ""��
���ڿ��ַ������ŷ��Ŷ���һ���������ǻ��Ĵ�

��ʾ��
1 <= s.length <= 2 * 10^5
s ���ɿɴ�ӡ�� ASCII �ַ����

ע�⣺��������վ 125 ����ͬ��https://leetcode-cn.com/problems/valid-palindrome/


*/

class Solution {
public:
	bool isPalindrome(string s) {
		int len = s.size();
		int left = 0, right = len - 1;
		while (left < right) {
			while (left < right && !isalnum(s[left])) ++left;
			while (left < right && !isalnum(s[right])) --right;
			if (left < right) {
				if (tolower(s[left]) != tolower(s[right])) return false;
				++left;
				--right;
			}
		}
		return true;
	}
};


