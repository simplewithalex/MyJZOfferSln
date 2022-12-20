#include "header.h"

/*

����һ������������ root ��һ��Ŀ���� k����������������д�������Ԫ�������ǵĺ͵��ڸ�����Ŀ�������򷵻� true��

ʾ�� 1��
����: root = [5,3,6,2,4,null,7], k = 9
���: true

ʾ�� 2��
����: root = [5,3,6,2,4,null,7], k = 28
���: false

��ʾ:
�������Ľڵ�����ķ�Χ��[1, 10^4]
-10^4 <= Node.val <= 10^4
��Ŀ���ݱ�֤������� root ��һ�� ��Ч �Ķ���������
-10^5 <= k <= 10^5

ע�⣺��������վ 653 ����ͬ�� https://leetcode-cn.com/problems/two-sum-iv-input-is-a-bst/

*/

class Solution1 {
private:
	unordered_set<int> hashSet;

public:
	bool findTarget(TreeNode *root, int k) {
		if (!root) return false;
		if (hashSet.count(root->val)) return true;
		hashSet.insert(k - root->val);
		return findTarget(root->left, k) || findTarget(root->right, k);
	}
};

// ����BST���ʣ�˫ָ��
class Solution2 {
private:
	vector<int> v;
	void inorder(TreeNode *node) {
		if (!node) return;
		inorder(node->left);
		v.push_back(node->val);
		inorder(node->right);
	}

public:
	bool findTarget(TreeNode *root, int k) {
		inorder(root);
		int left = 0, right = v.size() - 1;
		while (left < right) {
			if (v[left] + v[right] == k) {
				return true;
			} else if (v[left] + v[right] < k) {
				++left;
			} else {
				--right;
			}
		}
		return false;
	}
};