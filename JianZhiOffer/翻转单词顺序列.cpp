#include "header.h"

/*

��ȷ�ľ���Ӧ���ǡ�I am a student.��
���ӵ��ʵ�˳��ת��Ϊ��student. a am I��

*/

class Solution {
public:
	string ReverseSentence(string str)
	{
		reverse(str.begin(), str.end());
		for (auto it1 = str.begin(), it2 = str.begin(); it1 != str.end();)
		{
			if (*it1 == ' ')
			{
				++it1;
				++it2;
			}
			else if (it2 == str.end() || *it2 == ' ')
			{
				reverse(it1, it2);
				it1 = it2;
			}
			else
			{
				++it2;
			}
		}
		return str;
	}
};
