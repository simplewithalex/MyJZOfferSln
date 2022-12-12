#include "header.h"

/*

����һ�ö��������������е�һ���ڵ� p ���ҵ��ýڵ������е������̡�����ڵ�û�������̣��뷵�� null ��

�ڵ�p�ĺ����ֵ��p.val��Ľڵ��м�ֵ��С�Ľڵ㣬�������������˳��ڵ�p����һ���ڵ㡣

ʾ�� 1��
���룺root = [2,1,3], p = 1
�����2
���ͣ����� 1 ���������� 2����ע�� p �ͷ���ֵ��Ӧ�� TreeNode ���͡�

ʾ�� 2��
���룺root = [5,3,6,2,4,null,null,1], p = 6
�����null
���ͣ���Ϊ�����Ľڵ�û�������̣����Դ𰸾ͷ��� null �ˡ�

��ʾ��
���нڵ����Ŀ�ڷ�Χ [1, 10^4] �ڡ�
-10^5 <= Node.val <= 10^5
���и��ڵ��ֵ����֤Ψһ��

ע�⣺��������վ 285 ����ͬ�� https://leetcode-cn.com/problems/inorder-successor-in-bst/

*/

class Solution1 {
public:
	TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
		TreeNode *pre = nullptr;
		return inorder(root, p, pre);
	}

private:
	TreeNode *inorder(TreeNode *node, TreeNode *p, TreeNode *&pre) {
		if (!node) return nullptr;
		TreeNode *left = inorder(node->left, p, pre);
		if (left) return left;
		if (pre == p) return node;
		pre = node;
		return inorder(node->right, p, pre);
	}
};

class Solution2 {
public:
	TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
		if (!root) return nullptr;
		if (root->val <= p->val) return inorderSuccessor(root->right, p);
		TreeNode *left = inorderSuccessor(root->left, p);
		return left ? left : root;
	}
};