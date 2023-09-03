#include "header.h"


/*

LCR 117. �����ַ�����

��������ַ��� X �е�������ͬλ�õ���ĸ��ʹ�������ַ��� Y ��ȣ���ô�� X �� Y �����ַ������ơ�����������ַ�����������ȵģ�������Ҳ�����Ƶ�

���磬"tars" �� "rats" �����Ƶ� (���� 0 �� 2 ��λ��)�� "rats" �� "arts" Ҳ�����Ƶģ����� "star" ���� "tars"��"rats"���� "arts" ����

��֮������ͨ���������γ������������飺{"tars", "rats", "arts"} �� {"star"}��ע�⣬"tars" �� "arts" ����ͬһ���У���ʹ���ǲ�������

��ʽ�ϣ���ÿ������ԣ�Ҫȷ��һ�����������У�ֻ��Ҫ����ʺ͸���������һ����������

����һ���ַ����б� strs���б��е�ÿ���ַ������� strs �����������ַ�����һ����ĸ��λ�ʣ����� strs ���ж��ٸ������ַ����飿

ʾ�� 1��
���룺strs = ["tars","rats","arts","star"]
�����2

ʾ�� 2��
���룺strs = ["omv","ovm"]
�����1

��ʾ��
1 <= strs.length <= 300
1 <= strs[i].length <= 300
strs[i] ֻ����Сд��ĸ
strs �е����е��ʶ�������ͬ�ĳ��ȣ����Ǳ˴˵���ĸ��λ��

ע�⣺��������վ 839 ����ͬ��https://leetcode-cn.com/problems/similar-string-groups/

*/

// DFS
class Solution {
private:
	bool isSimila(const string &str1, const string &str2) {
		// ���������ж�����λ��
		int diff = 0;
		for (int i = 0; i < str1.size(); ++i) {
			if (str1[i] != str2[i]) ++diff;
		}
		return diff == 0 || diff == 2;
	}
	void dfs(int idx, vector<vector<int>> &adj, vector<char> &visited) {
		visited[idx] = true;
		for (const auto &n : adj[idx]) {
			if (!visited[n]) dfs(n, adj, visited);
		}
	}

public:
	int numSimilarGroups(vector<string> &strs) {
		int len = strs.size();
		vector<vector<int>> adj(len);
		for (int i = 0; i < len; ++i) {
			for (int j = i + 1; j < len; ++j) {
				if (isSimila(strs[i], strs[j])) {
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}
		vector<char> visited(len);
		int count = 0;
		for (int i = 0; i < len; ++i) {
			if (!visited[i]) {
				dfs(i, adj, visited);
				++count;
			}
		}
		return count;
	}
};
// https://leetcode.com/problems/similar-string-groups/editorial/

