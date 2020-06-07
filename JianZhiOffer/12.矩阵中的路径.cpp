#include "header.h"

/*

�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����һ��ʼ��ÿһ�������ھ����������ҡ��ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���ø��ӡ�
���磬�������3��4�ľ����а���һ���ַ�����bfce����·����
[
 ["a","b","c","e"],
 ["s","f","c","s"],
 ["a","d","e","e"]
]
�������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�

ʾ�� 1��
���룺board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
�����true

ʾ�� 2��
���룺board = [["a","b"],["c","d"]], word = "abcd"
�����false

��ʾ��
1 <= board.length <= 200
1 <= board[i].length <= 200
ע�⣺��������վ 79 ����ͬ��https://leetcode-cn.com/problems/word-search/


*/


class Solution {
public:
	bool exist(vector<vector<char>> &board, string word)
	{
		if (board.empty() || board[0].empty() || word.empty()) return false;
		int rows = board.size(), cols = board[0].size();
		vector<vector<char>> pathMap(rows, vector<char>(cols, false));
		for (int i = 0; i < rows; ++i)
		{
			for (int j = 0; j < cols; ++j)
			{
				if (helper(board, i, j, rows, cols, word, 0, pathMap)) return true;
			}
		}
		return false;
	}
	bool helper(vector<vector<char>> &board, int row, int col, int rows, int cols, string &word, int idx, vector<vector<char>> &pathMap)
	{
		int len = word.size();
		if (idx == len) return true;
		if (row < 0 || row == rows || col < 0 || col == cols || pathMap[row][col] == true || board[row][col] != word[idx]) return false;
		pathMap[row][col] = true;
		bool res = helper(board, row + 1, col, rows, cols, word, idx + 1, pathMap) ||
			helper(board, row, col + 1, rows, cols, word, idx + 1, pathMap) ||
			helper(board, row - 1, col, rows, cols, word, idx + 1, pathMap) ||
			helper(board, row, col - 1, rows, cols, word, idx + 1, pathMap);
		pathMap[row][col] = false;
		return res;
	}
};