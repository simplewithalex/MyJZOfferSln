#include "header.h"

/*

��ʵ��һ�����������ж��ַ����Ƿ��ʾ��ֵ������������С������
���磬�ַ���"+100","5e2","-123","3.1416"��"-1E-16"����ʾ��ֵ�� 
����"12e","1a3.14","1.2.3","+-5"��"12e+4.3"�����ǡ�

*/

class Solution {
public:
	bool isNumeric(char* s)
	{
		bool point = false, hasE = false, seeNum = false;
		int i = 0;
		for (; s[i] == ' '; ++i);
		int first = i;
		for (; s[i] != '\0'; ++i)
		{
			if (s[i] >= '0'&&s[i] <= '9')
			{
				seeNum = true;
			}
			else if (s[i] == '.')
			{
				if (hasE || point) return false;
				point = true;
			}
			else if (s[i] == 'E' || s[i] == 'e')
			{
				if (hasE || !seeNum) return false;
				hasE = true;
				seeNum = false;
			}
			else if (s[i] == '-' || s[i] == '+')
			{
				if (i != first && s[i - 1] != 'E'&s[i - 1] != 'e') return false;
			}
			else if (s[i] == ' ')
			{
				while (s[i] != '\0')
				{
					if (s[i] != ' ')
						return false;
					++i;
				}
			}
			else
				return false;
		}
		return seeNum;
	}
};