#include "header.h"

/*

Trie���������� "try"������˵ ǰ׺�� ��һ���������ݽṹ�����ڸ�Ч�ش洢�ͼ����ַ������ݼ��еļ���

��һ���ݽṹ���൱���Ӧ���龰�������Զ������ƴд��顣

����ʵ�� Trie �ࣺ
Trie() ��ʼ��ǰ׺������
void insert(String word) ��ǰ׺���в����ַ��� word
boolean search(String word) ����ַ��� word ��ǰ׺���У����� true�������ڼ���֮ǰ�Ѿ����룩�����򣬷���false
boolean startsWith(String prefix) ���֮ǰ�Ѿ�������ַ��� word ��ǰ׺֮һΪ prefix������ true�����򣬷���false

ʾ����
����
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
���
[null, null, true, false, true, null, true]

����
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // ���� True
trie.search("app");     // ���� False
trie.startsWith("app"); // ���� True
trie.insert("app");
trie.search("app");     // ���� True


��ʾ��
1 <= word.length, prefix.length <= 2000
word �� prefix ����СдӢ����ĸ���
insert��search �� startsWith ���ô����ܼƲ����� 3 * 10^4 ��

ע�⣺��������վ 208 ����ͬ��https://leetcode-cn.com/problems/implement-trie-prefix-tree/

*/

struct TrieNode {
	bool isWord;
	vector<TrieNode *> children;
	TrieNode() : isWord(false), children(26, nullptr) {}
};

class Trie {
private:
	TrieNode *root;

public:
	Trie() { root = new TrieNode(); }

	void insert(string word) {
		TrieNode *cur = root;
		int len = word.size();
		for (int i = 0; i < len; ++i) {
			char c = word[i] - 'a';
			if (!cur->children[c]) {
				cur->children[c] = new TrieNode();
			}
			cur = cur->children[c];
		}
		cur->isWord = true;
	}

	bool search(string word) {
		TrieNode *cur = root;
		int len = word.size();
		for (int i = 0; i < len; ++i) {
			char c = word[i] - 'a';
			if (!cur->children[c]) return false;
			cur = cur->children[c];
		}
		return cur->isWord;
	}

	bool startsWith(string prefix) {
		TrieNode *cur = root;
		int len = prefix.size();
		for (int i = 0; i < len; ++i) {
			char c = prefix[i] - 'a';
			if (!cur->children[c]) return false;
			cur = cur->children[c];
		}
		return true;
	}
};

// https://blog.csdn.net/m0_46202073/article/details/107253959

/**
* Your Trie object will be instantiated and called as such:
* Trie* obj = new Trie();
* obj->insert(word);
* bool param_2 = obj->search(word);
* bool param_3 = obj->startsWith(prefix);
*/

