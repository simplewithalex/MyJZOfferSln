#include "header.h"

/*

�����������һ����λָ�����ѭ�����ƣ�ROL���������и��򵥵����񣬾������ַ���ģ�����ָ�����������
����һ���������ַ�����S���������ѭ������Kλ������������
���磬�ַ�����S=��abcXYZdef��,Ҫ�����ѭ������3λ��Ľ��������XYZdefabc����

*/

class Solution {
public:
	string LeftRotateString(string str, int n)
	{
		if (str.empty() || n < 0) return{};
		int len = str.size();
		int num = n%len;
		string strROL = str.substr(num) + str.substr(0, num);
		return strROL;
	}
};

//�����ĿҲ�����ַ�����ת��������ã�������һ��˼·�ǣ�
//1����ת�ַ���ǰ��n���ַ���
//2����ת�ַ����ĺ��沿�֣�
//3����ת�����ַ�����