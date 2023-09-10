#include "header.h"

/*

LCR 114.���Ǵʵ�

����һ��ʹ��Ӣ����ĸ�����������ԣ��������Ե���ĸ˳����Ӣ��˳��ͬ

����һ���ַ����б� words����Ϊ�������ԵĴʵ䣬words �е��ַ����Ѿ������������Ե���ĸ˳�����������

������ݸôʵ仹ԭ������������֪����ĸ˳�򣬲�����ĸ����˳�����У��������ںϷ���ĸ˳�򣬷��� ""

�����ڶ��ֿ��ܵĺϷ���ĸ˳�򣬷������� ����һ�� ˳�򼴿�

�ַ��� s �ֵ�˳��С�� �ַ��� t �����������
�ڵ�һ����ͬ��ĸ������� s �е���ĸ�������������Ե���ĸ˳����λ�� t ����ĸ֮ǰ����ô s ���ֵ�˳��С�� t
���ǰ�� min(s.length, t.length) ��ĸ����ͬ����ô s.length < t.length ʱ��s ���ֵ�˳��ҲС�� t

ʾ�� 1��
���룺words = ["wrt","wrf","er","ett","rftt"]
�����"wertf"

ʾ�� 2��
���룺words = ["z","x"]
�����"zx"

ʾ�� 3��
���룺words = ["z","x","z"]
�����""
���ͣ������ںϷ���ĸ˳����˷��� ""

��ʾ��
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] ����СдӢ����ĸ���

ע�⣺��������վ 269 ����ͬ��https://leetcode-cn.com/problems/alien-dictionary/

*/

// DFS + ��������
class Solution1 {
private:
	const char VISITING = 1, VISITED = 2;
	unordered_map<char, vector<char>> edges;
	unordered_map<char, char> states;
	bool valid = true;
	string order;
	int index = 0;

private:
	void addEdge(const string &str1, const string &str2) {
		int len1 = str1.size(), len2 = str2.size();
		int len = min(len1, len2);
		int idx = 0;
		while (idx < len) {
			char c1 = str1[idx], c2 = str2[idx];
			if (c1 != c2) {
				edges[c1].emplace_back(c2);
				return;
			}
			++idx;
		}
		if (idx == len && len1 > len2) valid = false;
	}
	void dfs(char c) {
		states[c] = VISITING;
		for (const auto &v : edges[c]) {
			if (!states.count(v)) {
				dfs(v);
				if (!valid) return;
			} else if (states[v] == VISITING) {
				valid = false;
				return;
			}
		}
		states[c] = VISITED;
		order[index] = c;
		--index;
	}

public:
	string alienOrder(vector<string> &words) {
		int len = words.size();
		for (const auto &word : words) {
			int wordLen = word.size();
			for (int i = 0; i < wordLen; ++i) {
				char c = word[i];
				if (!edges.count(c)) edges[c] = vector<char>();
			}
		}
		for (int i = 1; i < len && valid; ++i) addEdge(words[i - 1], words[i]);
		if (!valid) return "";
		order = string(edges.size(), ' ');
		index = edges.size() - 1;
		for (const auto &p : edges) {
			if (!states.count(p.first)) dfs(p.first);
			if (!valid) return "";
		}
		return order;
	}
};


// BFS + ��������
class Solution2 {
private:
	unordered_map<char, vector<char>> edges;
	unordered_map<char, int> inDegrees;
	bool valid = true;

private:
	void addEdge(const string &str1, const string &str2) {
		int len1 = str1.size(), len2 = str2.size();
		int len = min(len1, len2);
		int idx = 0;
		while (idx < len) {
			char c1 = str1[idx], c2 = str2[idx];
			if (c1 != c2) {
				edges[c1].emplace_back(c2);
				++inDegrees[c2];
				return;
			}
			++idx;
		}
		if (idx == len && len1 > len2)
			valid = false;
	}

public:
	string alienOrder(vector<string> &words) {
		int len = words.size();
		for (const auto &word : words) {
			int wordLen = word.size();
			for (int i = 0; i < wordLen; ++i) {
				char c = word[i];
				if (!edges.count(c)) edges[c] = vector<char>();
			}
		}
		for (int i = 1; i < len && valid; ++i) addEdge(words[i - 1], words[i]);
		if (!valid) return "";
		queue<char> q;
		for (const auto &p : edges) {
			if (!inDegrees.count(p.first)) q.emplace(p.first);
		}
		string order;
		while (!q.empty()) {
			char u = q.front();
			q.pop();
			order.push_back(u);
			for (const auto &v : edges[u]) {
				--inDegrees[v];
				if (!inDegrees[v]) q.emplace(v);
			}
		}
		return order.size() == edges.size() ? order : "";
	}
};

