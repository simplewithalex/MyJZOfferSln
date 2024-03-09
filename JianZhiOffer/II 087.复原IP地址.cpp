#include "header.h"

/*

��ЧIP��ַ�������ĸ�������ÿ������λ�� 0 �� 255 ֮����ɣ��Ҳ��ܺ���ǰ�� 0��������֮���� '.' �ָ�
���磺"0.1.2.201" �� "192.168.1.1" ����ЧIP��ַ������ "0.011.255.245"��"192.168.1.312" �� "192.168@1.1" ����ЧIP��ַ
����һ��ֻ�������ֵ��ַ��� s �����Ա�ʾһ�� IP��ַ���������п��ܵ���ЧIP��ַ����Щ��ַ����ͨ���� s �в��� '.' ���γ�
�� ���� ���������ɾ�� s �е��κ�����
����԰� �κ� ˳�򷵻ش�

ʾ�� 1��
���룺s = "25525511135"
�����["255.255.11.135","255.255.111.35"]

ʾ�� 2��
���룺s = "0000"
�����["0.0.0.0"]

ʾ�� 3��
���룺s = "101023"
�����["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

��ʾ��
1 <= s.length <= 20
s �����������

ע�⣺��������վ 93 ����ͬ��https://leetcode-cn.com/problems/restore-ip-addresses/


*/

class Solution {
private:
	vector<string> res;
	vector<string> path;

public:
	vector<string> restoreIpAddresses(string s) {
		backtrack(s, 0);
		return res;
	}

private:
	void backtrack(const string &s, int start) {
		int len = s.size();
		if (start == len && path.size() == 4) {
			string str = path[0];
			for (int i = 1; i < path.size(); ++i) str += "." + path[i];
			res.push_back(str);
			return;
		}
		if (start < len && path.size() == 4) return;
		for (int subLen = 1; subLen <= 3; ++subLen) {
			if (start + subLen - 1 >= len) return;
			if (subLen != 1 && s[start] == '0') return;
			const string str = s.substr(start, subLen);
			if (subLen == 3 && stoi(str) > 255) return;
			path.push_back(str);
			backtrack(s, start + subLen);
			path.pop_back();
		}
	}
};
