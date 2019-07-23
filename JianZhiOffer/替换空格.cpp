#include "header.h"

/*

��ʵ��һ����������һ���ַ����е�ÿ���ո��滻�ɡ�%20����
���磬���ַ���ΪWe Are Happy.�򾭹��滻֮����ַ���ΪWe%20Are%20Happy��

*/

class Solution {
public:
	//��Ŀ�豣֤�滻�����鲻��Խ�磬����length�������������󳤶ȡ�
	void replaceSpace(char *str, int length)
	{
		if (!str || length <= 0)
			return;
		int originalLength = 0;
		int numberofBlank = 0;
		int i = 0;
		while (str[i] != '\0')
		{
			++originalLength;
			if (str[i] == ' ')
				++numberofBlank;
			++i;
		}
		int newlength = originalLength + numberofBlank * 2;
		if (newlength>length)
			return;
		int indexofOriginal = originalLength;
		int indexofNew = newlength;
		while (indexofOriginal >= 0 && indexofNew>indexofOriginal)
		{
			if (str[indexofOriginal] == ' ')
			{
				str[indexofNew--] = '0';
				str[indexofNew--] = '2';
				str[indexofNew--] = '%';
			}
			else
			{
				str[indexofNew--] = str[indexofOriginal];
			}
			--indexofOriginal;
		}
	}
};