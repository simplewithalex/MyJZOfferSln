#include "header.h"

/*

�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
���һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ� 
���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·����
���Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�

*/

class Solution
{
public:
	bool hasPath(char *matrix, int rows, int cols, char *str)
	{
		if (!matrix || !str) return false;
		vector<vector<bool>> pathMap(rows, vector<bool>(cols, true));
		for (int i = 0; i < rows; ++i)
			for (int j = 0; j < cols; ++j)
			{
				if (findPath(matrix, i, j, rows, cols, str, pathMap))
					return true;
			}
		return false;
	}
	bool findPath(char *matrix, int row, int col, int rows, int cols, char *str, vector<vector<bool>> &pathMap)
	{
		if (*str == '\0') return true;
		if (row < 0 || row == rows || col < 0 || col == cols || pathMap[row][col] == false)
		{
			return false;
		}
		if (matrix[row*cols + col] == *str)
		{
			pathMap[row][col] = false;
			if (findPath(matrix, row + 1, col, rows, cols, str + 1, pathMap) ||
				findPath(matrix, row - 1, col, rows, cols, str + 1, pathMap) ||
				findPath(matrix, row, col + 1, rows, cols, str + 1, pathMap) ||
				findPath(matrix, row, col - 1, rows, cols, str + 1, pathMap))
			{
				return true;
			}
			else
			{
				pathMap[row][col] = true;
				return false;
			}
		}
		else
		{
			return false;
		}
	}
};