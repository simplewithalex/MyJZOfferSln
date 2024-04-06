#include "header.h"

/*

LCR 113. �γ̱� II

�������ܹ��� numCourses �ſ���Ҫѡ����Ϊ 0 �� numCourses - 1
����һ������ prerequisites������ prerequisites[i] = [ai, bi]����ʾ��ѡ�޿γ� ai ǰ������ѡ�� bi

���磬��Ҫѧϰ�γ� 0������Ҫ����ɿγ� 1��������һ��ƥ������ʾ��[0,1]
������Ϊ��ѧ�����пγ������ŵ�ѧϰ˳�򡣿��ܻ��ж����ȷ��˳����ֻҪ���� ����һ�� �Ϳ����ˡ����������������пγ̣�����һ��������

ʾ�� 1��
���룺numCourses = 2, prerequisites = [[1,0]]
�����[0,1]
���ͣ��ܹ��� 2 �ſγ̡�Ҫѧϰ�γ� 1������Ҫ����ɿγ� 0����ˣ���ȷ�Ŀγ�˳��Ϊ [0,1]

ʾ�� 2��
���룺numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
�����[0,2,1,3]
���ͣ��ܹ��� 4 �ſγ̡�Ҫѧϰ�γ� 3����Ӧ������ɿγ� 1 �Ϳγ� 2�����ҿγ� 1 �Ϳγ� 2 ��Ӧ�����ڿγ� 0 ֮��
��ˣ�һ����ȷ�Ŀγ�˳���� [0,1,2,3] ����һ����ȷ�������� [0,2,1,3]

ʾ�� 3��
���룺numCourses = 1, prerequisites = []
�����[0]

��ʾ��
1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
����[ai, bi] ������ͬ


ע�⣺��������վ 210 ����ͬ��https://leetcode-cn.com/problems/course-schedule-ii/

*/

// �ο� LeetCode 210. �γ̱� II
class Solution {
private:
	vector<char> flags;
	vector<int> res;
	vector<vector<int>> adj;

public:
	vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
		adj.resize(numCourses);
		flags.resize(numCourses);
		for (const auto &p : prerequisites) adj[p[0]].push_back(p[1]);
		for (int i = 0; i < numCourses; ++i) {
			if (!dfs(i)) return {};
		}
		return res;
	}

private:
	bool dfs(int i) {
		if (flags[i] == 1) return false; // ���ڻ�
		if (flags[i] == -1) return true; // �ڵ����������
		// 0 ��ʾδ������1 ��ʾ�����У�-1 ��ʾ�������
		flags[i] = 1;
		for (const auto &next : adj[i]) {
			if (!dfs(next)) return false;
		}
		flags[i] = -1;
		res.push_back(i);
		return true;
	}
};
