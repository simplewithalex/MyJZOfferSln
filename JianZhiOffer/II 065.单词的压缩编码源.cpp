#include "header.h"

/*

LCR 065. ���ʵ�ѹ������

��������words����Ч���������������ַ��� s ���±����� indices ��ɣ������㣺
words.length == indices.length
�����ַ��� s �� '#' �ַ���β
����ÿ���±� indices[i]��s ��һ���� indices[i] ��ʼ������һ�� '#' �ַ��������������� '#'�������ַ���ǡ����words[i]���

����һ���������� words �����سɹ��� words ���б������С�����ַ��� s �ĳ���

ʾ�� 1��
���룺words = ["time", "me", "bell"]
�����10
���ͣ�һ����Ч����Ϊ s = "time#bell#" �� indices = [0, 2, 5] ��
words[0] = "time" ��s ��ʼ�� indices[0] = 0 ����һ�� '#' ���������ַ�������Ӵֲ�����ʾ "time#bell#"
words[1] = "me" ��s ��ʼ�� indices[1] = 2 ����һ�� '#' ���������ַ�������Ӵֲ�����ʾ "time#bell#"
words[2] = "bell" ��s ��ʼ�� indices[2] = 5 ����һ�� '#' ���������ַ�������Ӵֲ�����ʾ "time#bell#"

ʾ�� 2��
���룺words = ["t"]
�����2
���ͣ�һ����Ч����Ϊ s = "t#" �� indices = [0]

��ʾ��
1 <= words.length <= 2000
1 <= words[i].length <= 7
words[i] ����Сд��ĸ���


ע�⣺��������վ 820 ����ͬ�� https://leetcode-cn.com/problems/short-encoding-of-words/

*/


// DFS�����ڵ�

struct TrieNode1 {
	int childNum;
	vector<TrieNode1 *> children;
	TrieNode1() : childNum(0), children(26, nullptr) {}
};

class Trie1 {
public:
	TrieNode1 *root;
	int total = 0;

	Trie1() { root = new TrieNode1(); }

	void insert(const string &word) {
		TrieNode1 *cur = root;
		for (int i = word.size() - 1; i >= 0; --i) {
			char id = word[i] - 'a';
			if (!cur->children[id]) {
				cur->children[id] = new TrieNode1();
				++cur->childNum;
			}
			cur = cur->children[id];
		}
	}

	void searchLeaf(TrieNode1 *cur, int len) {
		if (cur->childNum == 0) total += len;
		for (const auto &child : cur->children) {
			if (child) searchLeaf(child, len + 1);
		}
	}
};

class Solution {
public:
	int minimumLengthEncoding(vector<string> &words) {
		Trie1 t;
		for (const auto &word : words) t.insert(word);
		t.searchLeaf(t.root, 1);
		return t.total;
	}
};



// ��ϣ���¼�ڵ�

struct TrieNode2 {
	int childNum;
	vector<TrieNode2 *> children;
	TrieNode2() : childNum(0), children(26, nullptr) {}
};

class Trie2 {
public:
	TrieNode2 *root;

	Trie2() { root = new TrieNode2(); }

	TrieNode2 *insert(const string &word) {
		TrieNode2 *cur = root;
		for (int i = word.size() - 1; i >= 0; --i) {
			char id = word[i] - 'a';
			if (!cur->children[id]) {
				cur->children[id] = new TrieNode2();
				++cur->childNum;
			}
			cur = cur->children[id];
		}
		return cur;
	}
};

class Solution2 {
public:
	int minimumLengthEncoding(vector<string> &words) {
		Trie2 t;
		unordered_map<TrieNode2 *, int> nodes_map;
		for (int i = 0; i < words.size(); ++i) {
			TrieNode2 *cur = t.insert(words[i]);
			nodes_map[cur] = i;
		}
		int res = 0;
		for (const auto &p : nodes_map) {
			if (p.first->childNum == 0) res += words[p.second].size() + 1;
		}
		return res;
	}
};
