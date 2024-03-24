#include "header.h"

/*

LCR 111. ������ֵ

����һ������������ equations ��һ��ʵ��ֵ���� values ��Ϊ��֪���������� equations[i] = [Ai, Bi] �� values[i] ��ͬ��ʾ��ʽ Ai / Bi = values[i] ��ÿ�� Ai �� Bi ��һ����ʾ�����������ַ�����

����һЩ������ queries ��ʾ�����⣬���� queries[j] = [Cj, Dj] ��ʾ�� j �����⣬���������֪�����ҳ� Cj / Dj = ? �Ľ����Ϊ�𰸡�

���� ��������Ĵ� ���������ĳ���޷�ȷ���Ĵ𰸣����� -1.0 �������𰸡���������г����˸�������֪������û�г��ֵ��ַ�����Ҳ��Ҫ�� -1.0 �������𰸡�

ע�⣺����������Ч�ģ�����Լ�����������в�����ֳ���Ϊ 0 ��������Ҳ������κ�ì�ܵĽ����
ע�⣺δ�ڵ�ʽ�б��г��ֵı�����δ����ģ�����޷�ȷ�����ǵĴ𰸡�

ʾ�� 1��
���룺equations = [["a","b"],["b","c"]], values = [2.0,3.0], queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
�����[6.00000,0.50000,-1.00000,1.00000,-1.00000]
���ͣ�
������a / b = 2.0, b / c = 3.0
���⣺a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
�����[6.0, 0.5, -1.0, 1.0, -1.0 ]
ע�⣺x ��δ����� => -1.0

ʾ�� 2��
���룺equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
�����[3.75000,0.40000,5.00000,0.20000]

ʾ�� 3��
���룺equations = [["a","b"]], values = [0.5], queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
�����[0.50000,2.00000,-1.00000,-1.00000]

��ʾ��
1 <= equations.length <= 20
equations[i].length == 2
1 <= Ai.length, Bi.length <= 5
values.length == equations.length
0.0 < values[i] <= 20.0
1 <= queries.length <= 20
queries[i].length == 2
1 <= Cj.length, Dj.length <= 5
Ai, Bi, Cj, Dj ��СдӢ����ĸ���������

ע�⣺��������վ 399 ����ͬ�� https://leetcode-cn.com/problems/evaluate-division/


*/

// DFS
class Solution1 {
private:
	unordered_map<string, unordered_map<string, double>> adjacent;
	unordered_set<string> visited;

public:
	vector<double> calcEquation(vector<vector<string>> &equations,
		vector<double> &values,
		vector<vector<string>> &queries) {
		vector<double> res;
		build(equations, values);
		for (auto q : queries) {
			double v = dfs(q[0], q[1]);
			if (v != -1) {
				res.push_back(v);
				adjacent[q[0]][q[1]] = v;
				adjacent[q[1]][q[0]] = 1 / v;
			} else {
				res.push_back(-1);
			}
		}
		return res;
	}

private:
	void build(vector<vector<string>> &equations, vector<double> &values) {
		for (int i = 0; i < equations.size(); ++i) {
			string a = equations[i][0];
			string b = equations[i][1];
			double v = values[i];
			adjacent[a][b] = v;
			adjacent[b][a] = 1 / v;
		}
	}
	double dfs(string begin, string end) {
		if (!adjacent.count(begin) || !adjacent.count(end)) return -1;
		if (visited.count(begin)) return -1;
		if (adjacent[begin].count(end)) return adjacent[begin][end];
		// ע��visited��ȫ�ֱ���������ʱ��Ҫ����ɾ����ǰ����Ԫ��
		// Ϊ�˱������ǣ�ʹ��һ����Χ�������res
		double res = -1.0;
		visited.insert(begin);
		for (auto p : adjacent[begin]) {
			double v = dfs(p.first, end);
			if (v != -1) {
				res = v * p.second;
				break;
			}
		}
		visited.erase(begin);
		return res;
	}
};


// BFS
class Solution2 {
private:
	unordered_map<string, int> equ;
	vector<vector<pair<int, double>>> adjacent;
	unordered_set<int> visited;

public:
	vector<double> calcEquation(vector<vector<string>> &equations,
		vector<double> &values,
		vector<vector<string>> &queries) {
		int len = equations.size();
		int id = 0;
		for (int i = 0; i < len; ++i) {
			if (!equ.count(equations[i][0])) equ[equations[i][0]] = id++;
			if (!equ.count(equations[i][1])) equ[equations[i][1]] = id++;
		}
		adjacent.resize(id);
		build(equations, values);
		vector<double> res;
		for (const auto &q : queries) {
			// ע��visited��ȫ�ֵģ�����ÿ�ο�ʼ�µ�����ֱ��clear
			visited.clear();
			double v = bfs(q[0], q[1]);
			if (v != -1) {
				res.push_back(v);
				adjacent[equ[q[0]]].push_back({ equ[q[1]], v });
				adjacent[equ[q[1]]].push_back({ equ[q[0]], 1.0 / v });
			} else {
				res.push_back(-1.0);
			}
		}
		return res;
	}

private:
	// ��ͼʱ�Ż���ʹ�ù�ϣ���ַ���ӳ��Ϊ����
	void build(vector<vector<string>> &equations, vector<double> &values) {
		for (int i = 0; i < equations.size(); ++i) {
			int va = equ[equations[i][0]], vb = equ[equations[i][1]];
			adjacent[va].push_back({ vb, values[i] });
			adjacent[vb].push_back({ va, 1.0 / values[i] });
		}
	}
	double bfs(string begin, string end) {
		if (!equ.count(begin) || !equ.count(end)) return -1.0;
		// ����ĸ��������൱�ڴ洢�˽ڵ�����Ȩ��
		queue<pair<int, double>> q;
		q.push({ equ[begin], 1.0 });
		while (!q.empty()) {
			const auto tmp = q.front();
			q.pop();
			if (visited.count(tmp.first)) continue;
			if (tmp.first == equ[end]) return tmp.second;
			visited.insert(tmp.first);
			for (const auto &p : adjacent[tmp.first]) {
				q.push({ p.first, tmp.second * p.second });
			}
		}
		return -1.0;
	}
};


// ���鼯
class UF {
private:
	vector<int> id;
	vector<double> weight;

public:
	UF(int total) {
		for (int i = 0; i < total; ++i) {
			id.push_back(i);
			weight.push_back(1.0);
		}
	}
	int find(int x) {
		if (id[x] != x) {
			int parent = id[x];
			id[x] = find(parent);
			weight[x] *= weight[parent];
		}
		return id[x];
	}
	void unionpq(int p, int q, double value) {
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot) return;
		id[pRoot] = qRoot;
		weight[pRoot] = weight[q] * value / weight[p];
	}
	double isConnected(int p, int q) {
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot) return weight[p] / weight[q];
		return -1.0;
	}
};

class Solution3 {
public:
	vector<double> calcEquation(vector<vector<string>> &equations,
		vector<double> &values,
		vector<vector<string>> &queries) {
		int len = equations.size();
		UF uf(2 * len);
		unordered_map<string, int> m;
		int id = 0;
		for (int i = 0; i < len; ++i) {
			string a = equations[i][0];
			string b = equations[i][1];
			if (!m.count(a)) m[a] = id++;
			if (!m.count(b)) m[b] = id++;
			uf.unionpq(m[a], m[b], values[i]);
		}
		int queriesLen = queries.size();
		vector<double> res;
		for (auto q : queries) {
			int id0 = m.count(q[0]) ? m[q[0]] : -1;
			int id1 = m.count(q[1]) ? m[q[1]] : -1;
			if (id0 == -1 || id1 == -1) res.push_back(-1.0);
			else res.push_back(uf.isConnected(id0, id1));
		}
		return res;
	}
};

// Floyd �㷨��Ԥ�ȼ������������֮��ľ���
class Solution4 {
private:
	unordered_map<string, int> equ;
	vector<vector<double>> graph;

public:
	vector<double> calcEquation(vector<vector<string>> &equations,
		vector<double> &values,
		vector<vector<string>> &queries) {
		int len = equations.size();
		int id = 0;
		for (int i = 0; i < len; ++i) {
			if (!equ.count(equations[i][0])) equ[equations[i][0]] = id++;
			if (!equ.count(equations[i][1])) equ[equations[i][1]] = id++;
		}
		graph.resize(id, vector<double>(id, -1.0));
		build(equations, values);
		for (int k = 0; k < id; ++k) {
			for (int i = 0; i < id; ++i) {
				for (int j = 0; j < id; ++j) {
					// ע�������·�����̫�����ܶ�ʧ���ȣ�Խ���õ����Խ��
					if (graph[i][j] == -1.0 && graph[i][k] > 0 && graph[k][j] > 0) {
						graph[i][j] = graph[i][k] * graph[k][j];
					}
				}
			}
		}
		vector<double> res;
		for (const auto &q : queries) {
			double result = -1.0;
			if (equ.count(q[0]) && equ.count(q[1])) {
				int va = equ[q[0]], vb = equ[q[1]];
				result = graph[va][vb] == -1.0 ? result : graph[va][vb];
			}
			res.push_back(result);
		}
		return res;
	}

private:
	void build(vector<vector<string>> &equations, vector<double> &values) {
		for (int i = 0; i < equations.size(); ++i) {
			int va = equ[equations[i][0]], vb = equ[equations[i][1]];
			graph[va][vb] = values[i];
			graph[vb][va] = 1.0 / values[i];
		}
	}
};

