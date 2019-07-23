#include "header.h"

/*

������һ��m�к�n�еķ���һ�������˴�����0,0�ĸ��ӿ�ʼ�ƶ���
ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� 
���磬��kΪ18ʱ���������ܹ����뷽��35,37������Ϊ3+5+3+7 = 18��
���ǣ������ܽ��뷽��35,38������Ϊ3+5+3+8 = 19��
���ʸû������ܹ��ﵽ���ٸ����ӣ�

*/


class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		if (rows <= 0 || cols <= 0) return 0;
		int num = 0;
		vector<vector<bool>> pathMap(rows, vector<bool>(cols, false));
		dfs(threshold, 0, 0, rows, cols, pathMap, num);
		return num;
	}
	void dfs(int k, int row, int col, int rows, int cols, vector<vector<bool>> &pathMap, int &num)
	{
		if (row == rows || row < 0 || col == cols || col < 0 || pathMap[row][col])
			return;
		int count = 0, i = row, j = col;
		while (i || j)
		{
			count += i % 10 + j % 10;
			i /= 10;
			j /= 10;
		}
		if (count>k) return;
		num += 1;
		pathMap[row][col] = true;
		dfs(k, row + 1, col, rows, cols, pathMap, num);
		dfs(k, row - 1, col, rows, cols, pathMap, num);
		dfs(k, row, col + 1, rows, cols, pathMap, num);
		dfs(k, row, col - 1, rows, cols, pathMap, num);
	}
};
