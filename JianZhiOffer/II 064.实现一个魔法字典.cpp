#include "header.h"

/*

LCR 064. ʵ��һ��ħ���ֵ�

���һ��ʹ�õ����б���г�ʼ�������ݽṹ�������б��еĵ��� ������ͬ

�������һ�����ʣ����ж��ܷ�ֻ�����������һ����ĸ������һ����ĸ��ʹ�����γɵ��µ��ʴ������㹹�����ֵ���

ʵ�� MagicDictionary �ࣺ
MagicDictionary() ��ʼ������
void buildDict(String[] dictionary) ʹ���ַ������� dictionary �趨�����ݽṹ��dictionary �е��ַ���������ͬ
bool search(String searchWord) ����һ���ַ��� searchWord���ж��ܷ�ֻ���ַ����� һ�� ��ĸ������һ����ĸ��ʹ�����γɵ����ַ����ܹ����ֵ��е���һ�ַ���ƥ�䡣
������ԣ����� true�����򷵻� false

ʾ����
����
["MagicDictionary", "buildDict", "search", "search", "search", "search"]
[[], [["hello", "leetcode"]], ["hello"], ["hhllo"], ["hell"], ["leetcoded"]]
���
[null, null, false, true, false, false]
����
MagicDictionary magicDictionary = new MagicDictionary();
magicDictionary.buildDict(["hello", "leetcode"]);
magicDictionary.search("hello"); // ���� False
magicDictionary.search("hhllo"); // ���ڶ��� 'h' �滻Ϊ 'e' ����ƥ�� "hello" �����Է��� True
magicDictionary.search("hell"); // ���� False
magicDictionary.search("leetcoded"); // ���� False

��ʾ��
1 <= dictionary.length <= 100
1 <= dictionary[i].length <= 100
dictionary[i] ����СдӢ����ĸ���
dictionary �е������ַ��� ������ͬ
1 <= searchWord.length <= 100
searchWord ����СдӢ����ĸ���
buildDict ���� search ֮ǰ����һ��
������ 100 �� search

ע�⣺��������վ 676 ����ͬ�� https://leetcode-cn.com/problems/implement-magic-dictionary/


*/


struct TrieNode {
	bool isWord;
	vector<TrieNode *> children;
	TrieNode() : isWord(false), children(26, nullptr) {}
};

class Trie {
public:
	TrieNode *root;

	Trie() { root = new TrieNode(); }

	void insert(const string &word) {
		TrieNode *cur = root;
		for (const auto &c : word) {
			char i = c - 'a';
			if (!cur->children[i]) {
				cur->children[i] = new TrieNode();
			}
			cur = cur->children[i];
		}
		cur->isWord = true;
	}

	bool search(const string &word, int idx, TrieNode *cur, int limit) {
		if (limit < 0) return false;
		if (idx == word.size()) return cur->isWord && limit == 0;
		int i = word[idx] - 'a';
		for (int j = 0; j < 26; ++j) {
			if (!cur->children[j]) continue;
			if (search(word, idx + 1, cur->children[j],
				i == j ? limit : limit - 1)) {
				return true;
			}
		}
		return false;
	}
};

class MagicDictionary {
private:
	Trie t;

public:
	MagicDictionary() {}

	void buildDict(vector<string> dictionary) {
		for (const auto &d : dictionary) t.insert(d);
	}

	bool search(string searchWord) {
		return t.search(searchWord, 0, t.root, 1);
	}
};

/**
* Your MagicDictionary object will be instantiated and called as such:
* MagicDictionary* obj = new MagicDictionary();
* obj->buildDict(dictionary);
* bool param_2 = obj->search(searchWord);
*/
