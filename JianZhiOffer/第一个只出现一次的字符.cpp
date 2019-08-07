#include "header.h"

/*

��һ���ַ���(0<=�ַ�������<=10000��ȫ������ĸ���)���ҵ���һ��ֻ����һ�ε��ַ�,����������λ��, 
���û���򷵻� -1����Ҫ���ִ�Сд��.

*/

class Solution1 {
public:
	int FirstNotRepeatingChar(string str)
	{
		if (str.empty()) return -1;
		vector<int> vec(60, 0);
		int len = str.size();
		for (int i = 0; i < len; ++i)
		{
			vec[str[i] - 'A'] += 1;
		}
		for (int i = 0; i < len; ++i)
		{
			if (vec[str[i] - 'A'] == 1)
				return i;
		}
		return -1;
	}
};

/*

��ʵ��һ�����������ҳ��ַ����е�һ��ֻ����һ�ε��ַ���
���磬�����ַ�����ֻ����ǰ�����ַ�"go"ʱ����һ��ֻ����һ�ε��ַ���"g"��
���Ӹ��ַ����ж���ǰ�����ַ���google"ʱ����һ��ֻ����һ�ε��ַ���"l"��

*/

class Solution2 {
public:
	vector<int> bucket = vector<int>(128, -1);
	int index = 0;
	//Insert one char from stringstream
	void Insert(char ch)
	{
		if (bucket[ch - 0] == -1)
			bucket[ch - 0] = index;
		else
			bucket[ch - 0] = -2;
		++index;
	}
	//return the first appearence once char in current stringstream
	char FirstAppearingOnce()
	{
		char ch = '#';
		int minindex = INT_MAX;;
		for (int i = 0; i < 128; ++i)
		{
			if (bucket[i] >= 0 && bucket[i]<minindex)
			{
				minindex = min(minindex, bucket[i]);
				ch = static_cast<char>(i);
			}
		}
		return ch;
	}
};
