#include "header.h"

/*

LCR 085. ��������

���� n �����������ŵĶ������������һ�������������ܹ��������п��ܵĲ��� ��Ч�� �������

ʾ�� 1��
���룺n = 3
�����["((()))","(()())","(())()","()(())","()()()"]

ʾ�� 2��
���룺n = 1
�����["()"]

��ʾ��
1 <= n <= 8

ע�⣺��������վ 22 ����ͬ�� https://leetcode-cn.com/problems/generate-parentheses/

*/


class Solution {
private:
	vector<string> res;

public:
	vector<string> generateParenthesis(int n) {
		if (n <= 0) return res;
		backtrack("", n, 0, 0);
		return res;
	}

private:
	void backtrack(string path, int n, int left, int right) {
		if (left > n || right > left) return;
		if (path.size() == n * 2) {
			res.push_back(path);
			return;
		}
		backtrack(path + '(', n, left + 1, right);
		backtrack(path + ')', n, left, right + 1);
	}
};

