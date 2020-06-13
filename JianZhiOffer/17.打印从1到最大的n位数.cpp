#include "header.h"

/*

�������� n����˳���ӡ���� 1 ������ n λʮ���������������� 3�����ӡ�� 1��2��3 һֱ������ 3 λ�� 999��

ʾ�� 1:
����: n = 1
���: [1,2,3,4,5,6,7,8,9]

˵����
�÷���һ�������б��������ӡ
n Ϊ������

*/

//��Ŀ�з��ص���int�����飬���Բ����ڴ�������
//���ֱ�Ӵ�ӡ�Ļ�������Ҫ���Ǵ������⣬�����ַ�������
class Solution {
private:
	vector<int> res;
	int start = 0, nineAnt = 0;
public:
	vector<int> printNumbers(int n)
	{
		vector<char> loop{ '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		string num(n, '0');
		start = n - 1;
		helper(0, n, num, loop);
		return res;
	}
	void helper(int x, int n, string &num, vector<char> &loop)
	{
		if (x == n)
		{
			string s = num.substr(start);
			if (s != "0") res.push_back(stoi(s));
			if (n - start == nineAnt) --start;
			return;
		}
		for (char i : loop)
		{
			if (i == '9') ++nineAnt;
			num[x] = i;
			helper(x + 1, n, num, loop);
		}
		--nineAnt;
	}
};
//https://leetcode-cn.com/problems/da-yin-cong-1dao-zui-da-de-nwei-shu-lcof/solution/mian-shi-ti-17-da-yin-cong-1-dao-zui-da-de-n-wei-2/