#include "header.h"

/*

��ָ Offer II 108. �����ݱ�

�ֵ� wordList �дӵ��� beginWord �� endWord �� ת������ ��һ������������γɵ����� beginWord -> s1 -> s2 -> ... -> sk��

ÿһ�����ڵĵ���ֻ��һ����ĸ
���� 1 <= i <= k ʱ��ÿ�� si ���� wordList �С�ע�⣬ beginWord ����Ҫ�� wordList ��
sk == endWord

������������ beginWord �� endWord ��һ���ֵ� wordList ������ �� beginWord �� endWord �� ���ת������ �е� ������Ŀ�����������������ת�����У����� 0

ʾ�� 1��
���룺beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
�����5
���ͣ�һ�����ת�������� "hit" -> "hot" -> "dot" -> "dog" -> "cog", �������ĳ��� 5

ʾ�� 2��
���룺beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
�����0
���ͣ�endWord "cog" �����ֵ��У������޷�����ת��

��ʾ��
1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord��endWord �� wordList[i] ��СдӢ����ĸ���
beginWord != endWord
wordList �е������ַ���������ͬ

ע�⣺��������վ 127 ����ͬ�� https://leetcode-cn.com/problems/word-ladder/

*/

class Solution1 {
public:
	int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
		queue<string> q;
		unordered_set<string> wordDict(wordList.begin(), wordList.end());
		if (!wordDict.count(endWord)) return 0;
		q.push(beginWord);
		wordDict.erase(beginWord);
		int ladder = 1;
		while (!q.empty()) {
			int len = q.size();
			for (int i = 0; i < len; ++i) {
				string tmp = q.front();
				q.pop();
				for (int j = 0; j < tmp.size(); ++j) {
					char c = tmp[j];
					for (int k = 0; k < 26; ++k) {
						tmp[j] = 'a' + k;
						if (wordDict.count(tmp)) {
							if (tmp == endWord) return ladder + 1;
							q.push(tmp);
							wordDict.erase(tmp);
						}
					}
					tmp[j] = c;
				}
			}
			++ladder;
		}
		return 0;
	}
};

// ˫��BFS
class Solution2 {
public:
	int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
		unordered_set<string> dict(wordList.begin(), wordList.end());
		unordered_set<string> head, tail;
		if (!dict.count(endWord)) return 0;
		head.insert(beginWord);
		tail.insert(endWord);
		int ladder = 2;
		while (!head.empty() && !tail.empty()) {
			if (head.size() > tail.size()) swap(head, tail);
			unordered_set<string> tmpset;
			for (auto it = head.begin(); it != head.end(); ++it) {
				string word = *it;
				for (int i = 0; i < word.size(); ++i) {
					char c = word[i];
					for (int j = 0; j < 26; ++j) {
						word[i] = 'a' + j;
						if (tail.count(word)) return ladder;
						if (dict.count(word)) {
							tmpset.insert(word);
							dict.erase(word);
						}
					}
					word[i] = c;
				}
			}
			++ladder;
			swap(head, tmpset);
		}
		return 0;
	}
};