#include "header.h"

/*

LCR 118. ��������

�����Կ�����һ����ͨ���޻�������ͼ

������һ�� n ���ڵ� (�ڵ�ֵ 1��n) ���������һ���ߺ��ͼ��
��ӵıߵ�������������� 1 �� n �м䣬���������ӵı߲����������Ѵ��ڵıߡ�
ͼ����Ϣ��¼�ڳ���Ϊ n �Ķ�ά���� edges ��edges[i] = [ai, bi] ��ʾͼ���� ai �� bi ֮�����һ���ߡ�

���ҳ�һ������ɾȥ�ıߣ�ɾ�����ʹ��ʣ�ಿ����һ������ n ���ڵ������
����ж���𰸣��򷵻����� edges �������ֵ��Ǹ���

ʾ�� 1��
����: edges = [[1,2], [1,3], [2,3]]
���: [2,3]

ʾ�� 2��
����: edges = [[1,2], [2,3], [3,4], [1,4], [1,5]]
���: [1,4]

��ʾ:
n == edges.length
3 <= n <= 1000
edges[i].length == 2
1 <= ai < bi <= edges.length
ai != bi
edges �����ظ�Ԫ��
������ͼ����ͨ��

ע�⣺��������վ 684 ����ͬ�� https://leetcode-cn.com/problems/redundant-connection/

*/


class UF {
private:
	vector<int> id;

public:
	UF(int total) {
		for (int i = 0; i < total; ++i) id.push_back(i);
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
	}
	bool isConnected(int p, int q) { return find(p) == find(q); }
};

class Solution {
public:
	vector<int> findRedundantConnection(vector<vector<int>> &edges) {
		int len = edges.size();
		UF uf(len + 1);
		for (const auto &edge : edges) {
			int p = edge[0], q = edge[1];
			if (!uf.isConnected(p, q)) uf.unionpq(p, q);
			else return edge;
		}
		return {};
	}
};
// https://leetcode.cn/problems/redundant-connection/solutions/557616/rong-yu-lian-jie-by-leetcode-solution-pks2/
// @author https://leetcode.cn/u/leetcode-solution/
// ����ͼ��ͨ�� ���� ���鼯������ͼ������ ���� ��ȹ�����ȡ���������
