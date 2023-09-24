#include "header.h"

/*

����һ�������� 0 �� 1, ��СΪ rows x cols �Ķ�ά�����ƾ����ҳ�ֻ���� 1 �������Σ������������

ʾ�� 1��
���룺matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
�����6
���ͣ�����������ͼ��ʾ

ʾ�� 2��
���룺matrix = []
�����0

ʾ�� 3��
���룺matrix = [["0"]]
�����0

ʾ�� 4��
���룺matrix = [["1"]]
�����1

ʾ�� 5��
���룺matrix = [["0","0"]]
�����0

��ʾ��
rows == matrix.length
cols == matrix[0].length
1 <= row, cols <= 200
matrix[i][j] Ϊ '0' �� '1'

ע�⣺��������վ 85 ����ͬ�����������ʽ��ͬ����https://leetcode.cn/problems/maximal-rectangle/

*/

// ǰ׺�� + ����ջ
class Solution {
public:
	int maximalRectangle(vector<string> &matrix) {
		if (matrix.empty() || matrix[0].empty()) return 0;
		int rows = matrix.size(), cols = matrix[0].size();
		// ÿһ�ж����ͷβ�ڱ�
		vector<vector<int>> sum(rows + 1, vector<int>(cols + 2, 0));
		int maxArea = 0;
		for (int i = 1; i <= rows; ++i) {
			for (int j = 1; j <= cols; ++j) {
				sum[i][j] = matrix[i - 1][j - 1] == '0' ? 0 : sum[i - 1][j] + 1;
			}
			maxArea = max(maxArea, largestRectangleArea(sum[i]));
		}
		return maxArea;
	}

private:
	int largestRectangleArea(const vector<int> &heights) {
		int ans = 0;
		stack<int> s;
		s.push(0);
		for (int i = 1; i < heights.size(); ++i) {
			while (heights[i] < heights[s.top()]) {
				int cur = s.top();
				s.pop();
				int left = s.top() + 1;
				int right = i - 1;
				ans = max(ans, (right - left + 1) * heights[cur]);
			}
			s.push(i);
		}
		return ans;
	}
};