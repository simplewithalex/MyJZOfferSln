#include "header.h"

/*

LCR 116. ʡ������

�� n �����У�����һЩ�˴���������һЩû��������������� a ����� b ֱ���������ҳ��� b ����� c ֱ����������ô���� a ����� c ���������

ʡ�� ��һ��ֱ�ӻ��������ĳ��У����ڲ�������û�������ĳ��С�

����һ�� n x n �ľ��� isConnected ������ isConnected[i][j] = 1 ��ʾ�� i �����к͵� j ������ֱ���������� isConnected[i][j] = 0 ��ʾ���߲�ֱ��������
���ؾ����� ʡ�� ��������

ʾ�� 1��
���룺isConnected = [[1,1,0],[1,1,0],[0,0,1]]
�����2

ʾ�� 2��
���룺isConnected = [[1,0,0],[0,1,0],[0,0,1]]
�����3

��ʾ��
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] Ϊ 1 �� 0
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]

ע�⣺��������վ 547 ����ͬ�� https://leetcode-cn.com/problems/number-of-provinces/

*/

// DFS
class Solution1 {
private:
	vector<char> visited;

public:
	int findCircleNum(vector<vector<int>> &isConnected) {
		int cities = isConnected.size();
		visited.resize(cities, false);
		int provinces = 0;
		for (int i = 0; i < cities; ++i) {
			if (!visited[i]) {
				dfs(isConnected, i);
				++provinces;
			}
		}
		return provinces;
	}

private:
	void dfs(vector<vector<int>> &isConnected, int i) {
		int len = isConnected.size();
		for (int j = 0; j < len; ++j) {
			if (isConnected[i][j] == 1 && !visited[j]) {
				visited[j] = true;
				dfs(isConnected, j);
			}
		}
	}
};


// BFS
class Solution2 {
public:
	int findCircleNum(vector<vector<int>> &isConnected) {
		int cities = isConnected.size();
		vector<char> visited(cities, false);
		int provinces = 0;
		queue<int> q;
		for (int i = 0; i < cities; ++i) {
			if (!visited[i]) {
				++provinces;
				q.push(i);
				visited[i] = true;
				while (!q.empty()) {
					int tmp = q.front();
					q.pop();
					for (int j = 0; j < cities; ++j) {
						if (isConnected[tmp][j] == 1 && !visited[j]) {
							visited[j] = true;
							q.push(j);
						}
					}
				}
			}
		}
		return provinces;
	}
};


// ���鼯
class UF {
private:
	vector<int> id;

public:
	int count;
	UF(int total) {
		count = 0;
		for (int i = 0; i < total; ++i) {
			id.push_back(i);
			++count;
		}
	}
	int find(int x) {
		if (x != id[x]) id[x] = find(id[x]);
		return id[x];
	}
	void unionpq(int p, int q) {
		int pRoot = find(p);
		int qRoot = find(q);
		if (pRoot == qRoot) return;
		id[pRoot] = qRoot;
		--count;
	}

	// bool isConnected(int p, int q) { return find(p) == find(q); }
};

class Solution3 {
public:
	int findCircleNum(vector<vector<int>> &isConnected) {
		int len = isConnected.size();
		UF uf(len);
		for (int i = 0; i < len; ++i) {
			for (int j = 0; j < i; ++j) {
				if (isConnected[i][j]) uf.unionpq(i, j);
			}
		}
		return uf.count;
	}
};

