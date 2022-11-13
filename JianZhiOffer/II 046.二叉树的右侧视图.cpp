#include "header.h"

/*

����һ���������ĸ��ڵ� root�������Լ�վ�������Ҳ࣬���մӶ������ײ���˳�򣬷��ش��Ҳ����ܿ����Ľڵ�ֵ��

ʾ�� 1:
����: [1,2,3,null,5,null,4]
���: [1,3,4]

ʾ�� 2:
����: [1,null,3]
���: [1,3]

ʾ�� 3:
����: []
���: []

��ʾ:
�������Ľڵ�����ķ�Χ�� [0,100]
-100 <= Node.val <= 100

ע�⣺��������վ 199 ����ͬ��https://leetcode-cn.com/problems/binary-tree-right-side-view/


*/

class Solution1 {
public:
	vector<int> rightSideView(TreeNode *root) {
		if (!root) return{};
		vector<int> res;
		helper(root, 0, res);
		return res;
	}

private:
	void helper(TreeNode *node, int depth, vector<int> &res) {
		if (!node) return;
		if (depth == res.size()) res.push_back(node->val);
		helper(node->right, depth + 1, res);
		helper(node->left, depth + 1, res);
	}
};

class Solution2 {
public:
	vector<int> rightSideView(TreeNode *root) {
		if (!root) return{};
		vector<int> res;
		queue<TreeNode *> q;
		q.push(root);
		TreeNode *cur = nullptr;
		while (!q.empty()) {
			int len = q.size();
			while (len--) {
				cur = q.front();
				q.pop();
				if (cur->left) q.push(cur->left);
				if (cur->right) q.push(cur->right);
			}
			res.push_back(cur->val);
		}
		return res;
	}
};