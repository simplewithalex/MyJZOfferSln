#include "header.h"

/*

给你一棵二叉搜索树的root，请你按中序遍历将其重新排列为一棵递增顺序搜索树。
使树中最左边的节点成为树的根节点，并且每个节点没有左子节点，只有一个右子节点。

示例 1：
输入：root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
输出：[1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]

示例 2：
输入：root = [5,1,7]
输出：[1,null,5,null,7]

提示：
树中节点数的取值范围是 [1, 100]
0 <= Node.val <= 1000

本题与主站 897 题相同： https://leetcode-cn.com/problems/increasing-order-search-tree/

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