#include "header.h"

/*

����һ���������������뽫����ÿ���ڵ��ֵ�滻�����д��ڻ��ߵ��ڸýڵ�ֵ�����нڵ�ֵ֮�͡�

����һ�£�������������������Լ��������
�ڵ���������������� С�� �ڵ���Ľڵ㡣
�ڵ���������������� ���� �ڵ���Ľڵ㡣
��������Ҳ�����Ƕ�����������

ʾ�� 1��
���룺root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
�����[30,36,21,36,35,26,15,null,null,null,33,null,null,null,8]

ʾ�� 2��
���룺root = [0,null,1]
�����[1,null,1]

ʾ�� 3��
���룺root = [1,0,2]
�����[3,3,2]

ʾ�� 4��
���룺root = [3,2,4,1]
�����[7,9,4,10]


��ʾ��
���еĽڵ������� 0 �� 10^4 ֮�䡣
ÿ���ڵ��ֵ���� -10^4 �� 10^4 ֮�䡣
���е�����ֵ������ͬ��
��������Ϊ������������

ע�⣺
��������վ 538 ����ͬ�� https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
��������վ 1038 ����ͬ��https://leetcode-cn.com/problems/binary-search-tree-to-greater-sum-tree/

*/

class Solution {
public:
	TreeNode *convertBST(TreeNode *root) {
		int sum = 0;
		helper(root, sum);
		return root;
	}

private:
	void helper(TreeNode *node, int &sum) {
		if (!node) return;
		helper(node->right, sum);
		node->val += sum;
		sum = node->val;
		helper(node->left, sum);
	}
};