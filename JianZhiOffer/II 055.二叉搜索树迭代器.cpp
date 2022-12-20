#include "header.h"

/*

��һ��������������������BSTIterator ����ʾһ�����������������������BST���ĵ�������

BSTIterator(TreeNode root) ��ʼ�� BSTIterator ���һ������BST �ĸ��ڵ� root ����Ϊ���캯����һ���ָ�����ָ��Ӧ��ʼ��Ϊһ���������� BST �е����֣��Ҹ�����С�� BST �е��κ�Ԫ�ء�

boolean hasNext() �����ָ���Ҳ�����������֣��򷵻� true �����򷵻� false ��

int next()��ָ�������ƶ���Ȼ�󷵻�ָ�봦�����֡�

ע�⣬ָ���ʼ��Ϊһ���������� BST �е����֣����Զ� next() ���״ε��ý����� BST �е���СԪ�ء�

���Լ��� next() ����������Ч�ģ�Ҳ����˵�������� next() ʱ��BST ��������������ٴ���һ����һ�����֡�



ʾ����
����
inputs = ["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
inputs = [[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
���
[null, 3, 7, true, 9, true, 15, true, 20, false]

����
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // ���� 3
bSTIterator.next();    // ���� 7
bSTIterator.hasNext(); // ���� True
bSTIterator.next();    // ���� 9
bSTIterator.hasNext(); // ���� True
bSTIterator.next();    // ���� 15
bSTIterator.hasNext(); // ���� True
bSTIterator.next();    // ���� 20
bSTIterator.hasNext(); // ���� False


��ʾ��
���нڵ����Ŀ�ڷ�Χ [1, 10^5] ��
0 <= Node.val <= 10^6
������ 10^5 �� hasNext �� next ����

���ף���������һ���������������Ľ��������next() �� hasNext() ������̯ʱ�临�Ӷ�Ϊ O(1) ����ʹ�� O(h) �ڴ档���� h �����ĸ߶ȡ�

ע�⣺��������վ 173 ����ͬ�� https://leetcode-cn.com/problems/binary-search-tree-iterator/

*/

class BSTIterator {
private:
	TreeNode *cur;
	stack<TreeNode *> stk;

public:
	BSTIterator(TreeNode *root) : cur(root) {}

	int next() {
		while (cur) {
			stk.push(cur);
			cur = cur->left;
		}
		cur = stk.top();
		stk.pop();
		int ret = cur->val;
		cur = cur->right;
		return ret;
	}

	bool hasNext() { return cur || !stk.empty(); }
};
/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */