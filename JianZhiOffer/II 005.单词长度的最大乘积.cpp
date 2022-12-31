#include "header.h"

/*

����һ���ַ������� words ���ҳ������� length(words[i]) * length(words[j]) �����ֵ���������������ʲ����й�����ĸ��
����������������������ʣ����� 0 ��

ʾ�� 1��
���룺words = ["abcw","baz","foo","bar","xtfn","abcdef"]
�����16
���ͣ�����������Ϊ "abcw", "xtfn"��

ʾ�� 2��
���룺words = ["a","ab","abc","d","cd","bcd","abcd"]
�����4
���ͣ�����������Ϊ "ab", "cd"��

ʾ�� 3��
���룺words = ["a","aa","aaa","aaaa"]
�����0
���ͣ��������������������ʡ�

��ʾ��
2 <= words.length <= 1000
1 <= words[i].length <= 1000
words[i] ������Сд��ĸ

ע�⣺��������վ 318 ����ͬ��https://leetcode-cn.com/problems/maximum-product-of-word-lengths/

*/

class Solution1 {
public:
	int maxProduct(vector<string>& words) {
		int len = words.size();
		vector<int> masks(len);
		for (int i = 0; i < len; ++i) {
			string word = words[i];
			for (const char &c : word) masks[i] |= 1 << (c - 'a');
		}
		int maxProd = 0;
		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j < len; ++j) {
				if ((masks[i] & masks[j]) == 0) maxProd = max(maxProd, (int)(words[i].size()*words[j].size()));
			}
		}
		return maxProd;
	}
};

class Solution2 {
public:
	int maxProduct(vector<string>& words) {
		int len = words.size();
		unordered_map<int, int> m;
		for (int i = 0; i < len; ++i) {
			int mask = 0;
			string word = words[i];
			for (const char &c : word) mask |= 1 << (c - 'a');
			if (m.count(mask)) {
				if (word.size() > m[mask]) m[mask] = word.size();
			} else {
				m[mask] = word.size();
			}
		}
		int maxProd = 0;
		for (const auto &p1 : m) {
			int wordLen1 = p1.second;
			for (const auto &p2 : m) {
				if ((p1.first & p2.first) == 0) {
					int wordLen2 = p2.second;
					maxProd = max(maxProd, wordLen1*wordLen2);
				}
			}
		}
		return maxProd;
	}
};