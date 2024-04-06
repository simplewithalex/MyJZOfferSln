#include "header.h"

/*

LCR 115. �����ؽ�

����һ������Ϊ n ���������� nums������ nums �Ƿ�ΧΪ [1��n] �����������С����ṩ��һ�� 2D �������� sequences������ sequences[i] �� nums �������С�
��� nums �Ƿ���Ψһ����� �����С���� ������ �� ������� �����У������������� sequences[i] �������������С����ڸ��������� sequences�����ܴ��ڶ����Ч�ĳ����С�

���磬���� sequences = [[1,2],[1,3]] ����������̵� ������ ��[1,2,3] �� [1,3,2]

������ sequences = [[1,2],[1,3],[1,2,3]] ��Ψһ���ܵ���� ������ �� [1,2,3]��[1,2,3,4] �ǿ��ܵĳ����У���������̵ġ�

��� nums �����е�Ψһ��� ������ ���򷵻� true�����򷵻� false
������ ��һ������ͨ������һ��������ɾ��һЩԪ�ػ�ɾ���κ�Ԫ�أ������ı�����Ԫ�ص�˳�������

ʾ�� 1��
���룺nums = [1,2,3], sequences = [[1,2],[1,3]]
�����false
���ͣ������ֿ��ܵĳ����У�[1,2,3]��[1,3,2]��
���� [1,2] ��[1,2,3]��[1,3,2]�������С�
���� [1,3] ��[1,2,3]��[1,3,2]�������С�
��Ϊ nums ����Ψһ��̵ĳ����У����Է���false��

ʾ�� 2��
���룺nums = [1,2,3], sequences = [[1,2]]
�����false
���ͣ���̿��ܵĳ�����Ϊ [1,2]��
���� [1,2] �����������У�[1,2]��
��Ϊ nums ������̵ĳ����У����Է���false��

ʾ�� 3��
���룺nums = [1,2,3], sequences = [[1,2],[1,3],[2,3]]
�����true
���ͣ���̿��ܵĳ�����Ϊ[1,2,3]��
���� [1,2] ������һ�������У�[1,2,3]��
���� [1,3] ������һ�������У�[1,2,3]��
���� [2,3] ������һ�������У�[1,2,3]��
��Ϊ nums ��Ψһ��̵ĳ����У����Է���true��

��ʾ��
n == nums.length
1 <= n <= 10^4
nums �� [1, n] ��Χ����������������
1 <= sequences.length <= 10^4
1 <= sequences[i].length <= 10^4
1 <= sum(sequences[i].length) <= 10^5
1 <= sequences[i][j] <= n
sequences ���������鶼�� Ψһ ��
sequences[i] �� nums ��һ��������


ע�⣺��������վ 444 ����ͬ��https://leetcode-cn.com/problems/sequence-reconstruction/

*/


class Solution {
public:
	bool sequenceReconstruction(vector<int> &nums,
		vector<vector<int>> &sequences) {
		int len = nums.size();
		vector<int> indegrees(len + 1);
		vector<unordered_set<int>> adj(len + 1);
		for (const auto &seq : sequences) {
			for (int i = 1; i < seq.size(); ++i) {
				int pre = seq[i - 1], cur = seq[i];
				if (!adj[pre].count(cur)) {
					adj[pre].insert(cur);
					++indegrees[cur];
				}
			}
		}
		queue<int> q;
		for (int i = 1; i <= len; ++i) {
			if (indegrees[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			if (q.size() > 1) return false;
			int idx = q.front();
			q.pop();
			for (const auto &next : adj[idx]) {
				if (--indegrees[next] == 0) q.push(next);
			}
		}
		return true;
	}
};
