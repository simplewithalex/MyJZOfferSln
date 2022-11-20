#include "header.h"

/*

����һ���������ĸ��ڵ� root ������ÿ���ڵ㶼�����һ�� 0 �� 9 ֮������֡�
ÿ���Ӹ��ڵ㵽Ҷ�ڵ��·��������һ�����֣�
���磬�Ӹ��ڵ㵽Ҷ�ڵ��·�� 1 -> 2 -> 3 ��ʾ���� 123 ��

����Ӹ��ڵ㵽Ҷ�ڵ����ɵ���������֮�͡�Ҷ�ڵ���ָû���ӽڵ�Ľڵ㡣

ʾ�� 1��
���룺root = [1,2,3]
�����25
���ͣ�
�Ӹ���Ҷ�ӽڵ�·�� 1->2 �������� 12
�Ӹ���Ҷ�ӽڵ�·�� 1->3 �������� 13
��ˣ������ܺ� = 12 + 13 = 25

ʾ�� 2��
���룺root = [4,9,0,5,1]
�����1026
���ͣ�
�Ӹ���Ҷ�ӽڵ�·�� 4->9->5 �������� 495
�Ӹ���Ҷ�ӽڵ�·�� 4->9->1 �������� 491
�Ӹ���Ҷ�ӽڵ�·�� 4->0 �������� 40
��ˣ������ܺ� = 495 + 491 + 40 = 1026

��ʾ��
���нڵ����Ŀ�ڷ�Χ [1, 1000] ��
0 <= Node.val <= 9
������Ȳ����� 10

ע�⣺��������վ 129 ����ͬ�� https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/

*/

// DFS
class Solution1 {
public:
	int sumNumbers(TreeNode *root) { return helper(root, 0); }

private:
	int helper(TreeNode *node, int preSum) {
		if (!node) return 0;
		int sum = preSum * 10 + node->val;
		if (!node->left && !node->right) {
			return sum;
		} else {
			return helper(node->left, sum) + helper(node->right, sum);
		}
	}
};

// BFS
class Solution2 {
public:
	int sumNumbers(TreeNode *root) {
		if (!root) return 0;
		int sum = 0;
		queue<TreeNode *> nodeq;
		queue<int> numq;
		nodeq.push(root);
		numq.push(root->val);
		while (!nodeq.empty()) {
			TreeNode *node = nodeq.front();
			int num = numq.front();
			nodeq.pop();
			numq.pop();
			TreeNode *left = node->left;
			TreeNode *right = node->right;
			if (!left && !right) {
				sum += num;
			} else {
				if (left) {
					nodeq.push(left);
					numq.push(num * 10 + left->val);
				}
				if (right) {
					nodeq.push(right);
					numq.push(num * 10 + right->val);
				}
			}
		}
		return sum;
	}
};