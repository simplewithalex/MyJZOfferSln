#include "header.h"

/*

����һ�ö�����������root�����㰴�������������������Ϊһ�õ���˳����������
ʹ��������ߵĽڵ��Ϊ���ĸ��ڵ㣬����ÿ���ڵ�û�����ӽڵ㣬ֻ��һ�����ӽڵ㡣

ʾ�� 1��
���룺root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
�����[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

ʾ�� 2��
���룺root = [5,1,7]
�����[1,null,5,null,7]

��ʾ��
���нڵ�����ȡֵ��Χ�� [1, 100]
0 <= Node.val <= 1000

��������վ 897 ����ͬ�� https://leetcode-cn.com/problems/increasing-order-search-tree/

*/

class Solution {
public:
	TreeNode *increasingBST(TreeNode *root) {
		TreeNode *dummy = new TreeNode(-1);
		TreeNode *cur = dummy;
		inorder(root, cur);
		return dummy->right;
	}

private:
	void inorder(TreeNode *node, TreeNode *&cur) {
		if (!node) return;
		inorder(node->left, cur);
		cur->right = node;
		node->left = nullptr;
		cur = node;
		inorder(node->right, cur);
	}
};