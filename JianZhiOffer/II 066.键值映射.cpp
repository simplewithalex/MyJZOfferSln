#include "header.h"

/*

LCR 066. ��ֵӳ��

���һ�� map���������¼��㣺
�ַ�����ʾ����������ʾֵ
���ؾ���ǰ׺���ڸ����ַ����ļ���ֵ���ܺ�

ʵ��һ�� MapSum �ࣺ

MapSum() ��ʼ�� MapSum ����

void insert(String key, int val) ���� key-val ��ֵ�ԣ��ַ�����ʾ�� key��������ʾֵ val
����� key �Ѿ����ڣ���ôԭ���ļ�ֵ�� key-value ����������µļ�ֵ��

int sum(string prefix) ���������Ը�ǰ׺ prefix ��ͷ�ļ� key ��ֵ���ܺ�

ʾ�� 1��
���룺
["MapSum", "insert", "sum", "insert", "sum"]
[[], ["apple", 3], ["ap"], ["app", 2], ["ap"]]
�����
[null, null, 3, null, 5]
���ͣ�
MapSum mapSum = new MapSum();
mapSum.insert("apple", 3);
mapSum.sum("ap");           // ���� 3 (apple = 3)
mapSum.insert("app", 2);
mapSum.sum("ap");           // ���� 5 (apple + app = 3 + 2 = 5)

��ʾ��
1 <= key.length, prefix.length <= 50
key �� prefix ����СдӢ����ĸ���
1 <= val <= 1000
������ 50 �� insert �� sum

ע�⣺��������վ 677 ����ͬ�� https://leetcode-cn.com/problems/map-sum-pairs/

*/

// DFS�����ڵ�

struct TrieNode1 {
	int val;
	vector<TrieNode1 *> children;
	TrieNode1() : val(0), children(26, nullptr) {}
};

class Trie1 {
private:
	TrieNode1 *root;

public:
	Trie1() { root = new TrieNode1(); }

	void insert(const string &word, int val) {
		TrieNode1 *cur = root;
		for (const auto &c : word) {
			char i = c - 'a';
			if (!cur->children[i]) {
				cur->children[i] = new TrieNode1();
			}
			cur = cur->children[i];
		}
		cur->val = val;
	}

	TrieNode1 *searchPrefix(const string &word) {
		TrieNode1 *cur = root;
		for (const auto &c : word) {
			char i = c - 'a';
			cur = cur->children[i];
			if (!cur) return nullptr;
		}
		return cur;
	}

	int searchLeaf(TrieNode1 *node) {
		if (!node) return 0;
		int res = node->val;
		for (const auto &child : node->children) {
			res += searchLeaf(child);
		}
		return res;
	}

};

class MapSum1 {
private:
	Trie1 t;

public:
	MapSum1() {}

	void insert(string key, int val) { t.insert(key, val); }

	int sum(string prefix) {
		TrieNode1 *cur = t.searchPrefix(prefix);
		return cur == nullptr ? 0 : t.searchLeaf(cur);
	}
};



// ��ϣ���¼�ڵ�

struct TrieNode2 {
	int val;
	vector<TrieNode2 *> children;
	TrieNode2() : val(0), children(26, nullptr) {}
};

class Trie2 {
private:
	TrieNode2 *root;
	unordered_map<string, int> m;

public:
	Trie2() { root = new TrieNode2(); }

	void insert(const string &word, int val) {
		TrieNode2 *cur = root;
		int tmp = val;
		if (m.count(word)) tmp -= m[word];
		m[word] = val;
		for (const auto &c : word) {
			char i = c - 'a';
			if (!cur->children[i]) {
				cur->children[i] = new TrieNode2();
			}
			cur = cur->children[i];
			cur->val += tmp;
		}
	}

	int searchPrefixVal(const string &word) {
		TrieNode2 *cur = root;
		for (const auto &c : word) {
			char i = c - 'a';
			cur = cur->children[i];
			if (!cur) return 0;
		}
		return cur->val;
	}
};

class MapSum2 {
private:
	Trie2 t;

public:
	MapSum2() {}

	void insert(string key, int val) { t.insert(key, val); }

	int sum(string prefix) { return t.searchPrefixVal(prefix); }
};

/**
* Your MapSum object will be instantiated and called as such:
* MapSum* obj = new MapSum();
* obj->insert(key,val);
* int param_2 = obj->sum(prefix);
*/
