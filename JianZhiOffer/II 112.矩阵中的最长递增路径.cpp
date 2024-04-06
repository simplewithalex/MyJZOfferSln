#include "header.h"

/*

LCR 112. �����е������·��

����һ�� m x n �������� matrix���ҳ����� �����·�� �ĳ���
����ÿ����Ԫ����������ϣ��£������ĸ������ƶ�
������ �Խ��� �������ƶ����ƶ����߽��⣨���������ƣ�

ʾ�� 1��
���룺matrix = [[9,9,4],[6,6,8],[2,1,1]]
�����4
���ͣ������·��Ϊ [1, 2, 6, 9]

ʾ�� 2��
���룺matrix = [[3,4,5],[3,2,6],[2,2,1]]
�����4
���ͣ������·���� [3, 4, 5, 6]��ע�ⲻ�����ڶԽ��߷������ƶ�

ʾ�� 3��
���룺matrix = [[1]]
�����1

��ʾ��
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 2^31 - 1

ע�⣺��������վ 329 ����ͬ�� https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/

*/


// �ο� LeetCode 329.�����е������·��

// BFS + ��������
class Solution {
private:
	// �ྲ̬��Ա��ʼ��ʹ�ó������ʽ������ʱ��ֱ����ֵ
	// https://blog.csdn.net/qq_34801642/article/details/104948850
	static constexpr int dirs[4][2] = { { -1, 0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
	int rows;
	int cols;

public:
	int longestIncreasingPath(vector<vector<int>> &matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int rows = matrix.size(), cols = matrix[0].size();
		vector<vector<int>> outDgree(rows, vector<int>(cols, 0));
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				for (auto dir : dirs) {
					int newRow = i + dir[0], newCol = j + dir[1];
					if (newRow >= 0 && newRow < rows && newCol >= 0 &&
						newCol < cols && matrix[newRow][newCol] > matrix[i][j]) {
						++outDgree[i][j];
					}
				}
			}
		}
		queue<vector<int>> q;
		for (int i = 0; i < rows; ++i) {
			for (int j = 0; j < cols; ++j) {
				if (outDgree[i][j] == 0) q.push({ i, j });
			}
		}
		int ans = 0;
		while (!q.empty()) {
			++ans;
			int len = q.size();
			for (int i = 0; i < len; ++i) {
				vector<int> pos = q.front();
				q.pop();
				int row = pos[0], col = pos[1];
				for (auto dir : dirs) {
					int newRow = row + dir[0], newCol = col + dir[1];
					if (newRow >= 0 && newRow < rows && newCol >= 0 &&
						newCol < cols && matrix[newRow][newCol] < matrix[row][col]) {
						if (--outDgree[newRow][newCol] == 0) q.push({ newRow, newCol });
					}
				}
			}
		}
		return ans;
	}
};

