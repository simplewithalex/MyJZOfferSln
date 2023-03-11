#include "header.h"

/*

��ָ Offer II 106. ����ͼ

����һ������ͼ��ͼ���� n ���ڵ㡣����ÿ���ڵ㶼��һ������ 0 �� n - 1 ֮���Ψһ��š�����һ����ά���� graph������ graph[u] ��һ���ڵ����飬�ɽڵ� u ���ڽӽڵ���ɡ�
��ʽ�ϣ����� graph[u] �е�ÿ�� v��������һ��λ�ڽڵ� u �ͽڵ� v ֮�������ߡ�������ͼͬʱ�����������ԣ�
�������Ի���graph[u] ������ u��
������ƽ�бߣ�graph[u] �������ظ�ֵ��
��� v �� graph[u] �ڣ���ô u ҲӦ���� graph[v] �ڣ���ͼ������ͼ��
���ͼ���ܲ�����ͨͼ��Ҳ����˵�����ڵ� u �� v ֮����ܲ�����һ����ͨ�˴˵�·��

����ͼ���壺����ܽ�һ��ͼ�Ľڵ㼯�Ϸָ�������������Ӽ� A �� B ����ʹͼ�е�ÿһ���ߵ������ڵ�һ������ A ���ϣ�һ������ B ���ϣ��ͽ����ͼ��Ϊ����ͼ
���ͼ�Ƕ���ͼ������ true�����򣬷��� false

ʾ�� 1��
���룺graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
�����false
���ͣ����ܽ��ڵ�ָ�������������Ӽ�����ʹÿ���߶���ͨһ���Ӽ��е�һ���ڵ�����һ���Ӽ��е�һ���ڵ㡣

ʾ�� 2��
���룺graph = [[1,3],[0,2],[1,3],[0,2]]
�����true
���ͣ����Խ��ڵ�ֳ�����: {0, 2} �� {1, 3} ��

��ʾ��
graph.length == n
1 <= n <= 100
0 <= graph[u].length < n
0 <= graph[u][i] <= n - 1
graph[u] ������� u
graph[u] ������ֵ ������ͬ
��� graph[u] ���� v����ô graph[v] Ҳ����� u

ע�⣺��������վ 785 ����ͬ�� https://leetcode-cn.com/problems/is-graph-bipartite/


*/

// DFS
class Solution1 {
public:
	bool isBipartite(vector<vector<int>> &graph) {
		vector<int> visited(graph.size());
		for (int i = 0; i < graph.size(); ++i) {
			if (!visited[i] && !dfs(graph, i, 1, visited)) return false;
		}
		return true;
	}

private:
	bool dfs(vector<vector<int>> &graph, int u, int color,
		vector<int> &visited) {
		if (visited[u]) return visited[u] == color;
		visited[u] = color;
		for (int v : graph[u]) {
			if (!dfs(graph, v, -color, visited)) return false;
		}
		return true;
	}
};

// BFS
class Solution2 {
public:
	bool isBipartite(vector<vector<int>> &graph) {
		vector<int> visted(graph.size());
		queue<int> q;
		for (int i = 0; i < graph.size(); ++i) {
			if (visted[i]) continue;
			q.push(i);
			visted[i] = 1;
			while (!q.empty()) {
				int u = q.front();
				q.pop();
				for (int v : graph[u]) {
					if (visted[v] == visted[u]) return false;
					if (!visted[v]) {
						visted[v] = -visted[u];
						q.push(v);
					}
				}
			}
		}
		return true;
	}
};

// ���鼯
class UF {
private:
	vector<int> id;

public:
	UF(int total) {
		for (int i = 0; i < total; ++i) id.push_back(i);
	}
	int find(int x) {
		if (id[x] != x) id[x] = find(id[x]);
		return id[x];
	}
	void unionpq(int p, int q) {
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot) return;
		id[pRoot] = qRoot;
	}
	bool isConnected(int p, int q) { return find(p) == find(q); }
};

class Solution3 {
public:
	bool isBipartite(vector<vector<int>> &graph) {
		UF uf(graph.size());
		for (int i = 0; i < graph.size(); ++i) {
			for (int v : graph[i]) {
				if (uf.isConnected(v, i)) return false;
				uf.unionpq(graph[i][0], v);
			}
		}
		return true;
	}
};

// https://leetcode.cn/problems/is-graph-bipartite/solutions/333138/bfs-dfs-bing-cha-ji-san-chong-fang-fa-pan-duan-er-/
// @author https://leetcode.cn/u/sweetiee/

