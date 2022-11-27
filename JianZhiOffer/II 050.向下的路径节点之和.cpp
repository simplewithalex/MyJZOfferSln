#include "header.h"

/*

����һ���������ĸ��ڵ� root ����һ������ targetSum ����ö�������ڵ�ֵ֮�͵��� targetSum ��·������Ŀ��
·������Ҫ�Ӹ��ڵ㿪ʼ��Ҳ����Ҫ��Ҷ�ӽڵ����������·��������������µģ�ֻ�ܴӸ��ڵ㵽�ӽڵ㣩��

ʾ�� 1��
���룺root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
�����3
���ͣ��͵��� 8 ��·���� 3 ����

ʾ�� 2��
���룺root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
�����3

��ʾ:
�������Ľڵ�����ķ�Χ�� [0,1000]
-109 <= Node.val <= 10^9
-1000 <= targetSum <= 1000

ע�⣺��������վ 437 ����ͬ��https://leetcode-cn.com/problems/path-sum-iii/

*/

class Solution1 {
public:
	int pathSum(TreeNode *root, int targetSum) {
		if (!root) return 0;
		return helper(root, targetSum) + pathSum(root->left, targetSum) +
			pathSum(root->right, targetSum);
	}

private:
	int helper(TreeNode *node, int targetSum) {
		if (!node) return 0;
		int ret = 0;
		if (node->val == targetSum) ++ret;
		ret += helper(node->left, targetSum - node->val);
		ret += helper(node->right, targetSum - node->val);
		return ret;
	}
};

class Solution2 {
public:
	int pathSum(TreeNode *root, int targetSum) {
		if (!root) return 0;
		unordered_map<long long, int> prefix;
		prefix[0] = 1;
		return helper(root, targetSum, 0, prefix);
	}

private:
	int helper(TreeNode *node, int targetSum, long long cur,
		unordered_map<long long, int> &prefix) {
		if (!node) return 0;
		int ret = 0;
		cur += node->val;
		if (prefix.count(cur - targetSum)) ret = prefix[cur - targetSum];
		++prefix[cur];
		ret += helper(node->left, targetSum, cur, prefix);
		ret += helper(node->right, targetSum, cur, prefix);
		--prefix[cur];
		return ret;
	}
};
