#include "header.h"

/*

LCR 063. �����滻

��Ӣ���У�������һ������ �ʸ�(root) �ĸ�����Դʸ������������һЩ�������һ���ϳ��ĵ��ʣ����ǳ������Ϊ �̳д�(successor)��

���磬�ʸ�an�������ŵ��� other(����)�������γ��µĵ��� another(��һ��)��

���ڣ�����һ�������ʸ���ɵĴʵ� dictionary ��һ���ÿո�ָ������γɵľ��� sentence������Ҫ�������е����м̳д��ôʸ��滻����

����̳д����������γ����Ĵʸ���������̵Ĵʸ��滻��������Ҫ����滻֮��ľ��ӡ�

ʾ�� 1��
���룺dictionary = ["cat","bat","rat"], sentence = "the cattle was rattled by the battery"
�����"the cat was rat by the bat"

ʾ�� 2��
���룺dictionary = ["a","b","c"], sentence = "aadsfasf absbs bbab cadsfafs"
�����"a a b c"

��ʾ��
1 <= dictionary.length <= 1000
1 <= dictionary[i].length <= 100
dictionary[i] ����Сд��ĸ��ɡ�
1 <= sentence.length <= 10^6
sentence ����Сд��ĸ�Ϳո���ɡ�
sentence �е��ʵ������ڷ�Χ [1, 1000] �ڡ�
sentence ��ÿ�����ʵĳ����ڷ�Χ [1, 1000] �ڡ�
sentence �е���֮����һ���ո������
sentence û��ǰ����β��ո�

ע�⣺��������վ 648 ����ͬ�� https://leetcode-cn.com/problems/replace-words/


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

	string queryPrefix(const string &word) {
		TrieNode *cur = root;
		string res;
		for (const auto &c : word) {
			char i = c - 'a';
			res += c;
			if (!cur->children[i]) return word;
			if (cur->children[i]->isWord) return res;
			cur = cur->children[i];
		}
		return res;
	}
};

class Solution {
public:
	string replaceWords(vector<string> &dictionary, string sentence) {
		Trie t;
		for (const auto &d : dictionary) t.insert(d);
		stringstream ss(sentence);
		string res, word;
		while (ss >> word) res += t.queryPrefix(word) + " ";
		res.pop_back();
		return res;
	}
};

