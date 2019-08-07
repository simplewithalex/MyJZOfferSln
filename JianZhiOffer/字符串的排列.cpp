#include "header.h"

/*

����һ���ַ���,���ֵ����ӡ�����ַ������ַ����������С�
���������ַ���abc,���ӡ�����ַ�a,b,c�������г����������ַ���abc,acb,bac,bca,cab��cba��

*/

class Solution {
public:
	vector<string> Permutation(string str)
	{
		if (str.empty()) return{};
		vector<string> res;
		dfs(str, 0, res);
		sort(res.begin(), res.end());
		return res;
	}
	void dfs(string str, int i, vector<string> &res)
	{
		int len = str.size();
		if (i == len)
		{
			res.push_back(str);
			return;
		}
		for (int j = i; j < len; ++j)
		{
			if (i != j&&str[i] == str[j])
				continue;
			swap(str[i], str[j]);
			dfs(str, i + 1, res);
			swap(str[i], str[j]);
		}
	}
};