#include "header.h"

/*

LCR 110. ���п��ܵ�·��

����һ���� n ���ڵ�� �����޻�ͼ��DAG���������ҳ����дӽڵ� 0 ���ڵ� n-1 ��·�����������Ҫ���ض�˳��
graph[i] ��һ���ӽڵ� i ���Է��ʵ����нڵ���б����ӽڵ� i ���ڵ� graph[i][j]����һ������ߣ�

ʾ�� 1��
���룺graph = [[1,2],[3],[3],[]]
�����[[0,1,3],[0,2,3]]
���ͣ�������·�� 0 -> 1 -> 3 �� 0 -> 2 -> 3

ʾ�� 2��
���룺graph = [[4,3,1],[3,2,4],[3],[4],[]]
�����[[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]

��ʾ��
n == graph.length
2 <= n <= 15
0 <= graph[i][j] < n
graph[i][j] != i�����������Ի���
graph[i] �е�����Ԫ�� ������ͬ
��֤����Ϊ �����޻�ͼ��DAG��

ע�⣺��������վ 797 ����ͬ��https://leetcode-cn.com/problems/all-paths-from-source-to-target/

*/

// DFS
class Solution1 {
private:
	vector<int> path;
	vector<vector<int>> res;

public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
		path.push_back(0);
		dfs(graph, 0);
		return res;
	}

private:
	void dfs(vector<vector<int>> &graph, int idx) {
		if (idx == graph.size() - 1) {
			res.push_back(path);
			return;
		}
		for (int i = 0; i < graph[idx].size(); ++i) {
			path.push_back(graph[idx][i]);
			dfs(graph, graph[idx][i]);
			path.pop_back();
		}
	}
};

// BFS
class Solution2 {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
		int len = graph.size();
		vector<vector<int>> res;
		queue<vector<int>> q;
		q.push({ 0 });
		while (!q.empty()) {
			vector<int> tempath = q.front();
			int idx = tempath.back();
			q.pop();
			if (idx == len - 1) {
				res.push_back(tempath);
				continue;
			}
			for (int i = 0; i < graph[idx].size(); ++i) {
				tempath.push_back(graph[idx][i]);
				q.push(tempath);
				tempath.pop_back();
			}
		}
		return res;
	}
};

