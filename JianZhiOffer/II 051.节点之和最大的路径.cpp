#include "header.h"

/*

·�� ������Ϊһ������������ڵ�������ظ��ڵ�-�ӽڵ����ӣ��ﵽ����ڵ�����С�
ͬһ���ڵ���һ��·���������������һ�Ρ���·�����ٰ���һ���ڵ㣬�Ҳ�һ���������ڵ㡣
·������·���и��ڵ�ֵ���ܺ͡�
����һ���������ĸ��ڵ�root �����������·���� ��

ʾ�� 1��
���룺root = [1,2,3]
�����6
���ͣ�����·���� 2 -> 1 -> 3 ��·����Ϊ 2 + 1 + 3 = 6

ʾ�� 2��
���룺root = [-10,9,20,null,null,15,7]
�����42
���ͣ�����·���� 15 -> 20 -> 7 ��·����Ϊ 15 + 20 + 7 = 42

��ʾ��
���нڵ���Ŀ��Χ�� [1, 3 * 10^4]
-1000 <= Node.val <= 1000

ע�⣺��������վ 124 ����ͬ�� https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/

*/

class Solution {
public:
	int maxPathSum(TreeNode *root) {
		int maxSum = INT_MIN;
		helper(root, maxSum);
		return maxSum;
	}

private:
	int helper(TreeNode *node, int &maxSum) {
		if (!node) return 0;
		int left = max(helper(node->left, maxSum), 0);
		int right = max(helper(node->right, maxSum), 0);
		maxSum = max(left + right + node->val, maxSum);
		return node->val + max(left, right);
	}
};