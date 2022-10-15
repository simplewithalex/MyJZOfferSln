#include "header.h"

/*

��ȫ������ ��ÿһ�㣨�����һ���⣩������ȫ��䣨�����ڵ����ﵽ��󣩵ģ��������еĽڵ㶼�����ܵؼ�������ࡣ

���һ���㷨����һ���½ڵ���뵽һ�������Ķ������У����ڲ���󱣳���������

ʵ�� CBTInserter ��:

CBTInserter(TreeNode root) ʹ��ͷ�ڵ�Ϊ root �ĸ�������ʼ�������ݽṹ��
CBTInserter.insert(int v)  �����в���һ��ֵΪ Node.val == val���½ڵ� TreeNode��ʹ��������ȫ��������״̬�������ز���ڵ� TreeNode �ĸ��ڵ��ֵ��
CBTInserter.get_root() ����������ͷ�ڵ㡣


ʾ�� 1��
����
["CBTInserter", "insert", "insert", "get_root"]
[[[1, 2]], [3], [4], []]
���
[null, 1, 2, [1, 2, 3, 4]]
���ͣ�
CBTInserter cBTInserter = new CBTInserter([1, 2]);
cBTInserter.insert(3);  // ���� 1
cBTInserter.insert(4);  // ���� 2
cBTInserter.get_root(); // ���� [1, 2, 3, 4]

��ʾ��
���нڵ�������ΧΪ [1, 1000]
0 <= Node.val <= 5000
root ����ȫ������
0 <= val <= 5000
ÿ���������������� insert �� get_root ���� 10^4 ��

ע�⣺��������վ 919 ����ͬ�� https://leetcode-cn.com/problems/complete-binary-tree-inserter/

*/

// ����
class CBTInserter1 {
private:
	queue<TreeNode *> candidate;
	TreeNode *root;

public:
	CBTInserter1(TreeNode *root) {
		this->root = root;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			TreeNode *temp = q.front();
			q.pop();
			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
			if (!(temp->left && temp->right)) candidate.push(temp);
		}
	}

	int insert(int val) {
		TreeNode *child = new TreeNode(val);
		TreeNode *parent = candidate.front();
		if (!parent->left) {
			parent->left = child;
		}
		else {
			parent->right = child;
			candidate.pop();
		}
		candidate.push(child);
		return parent->val;
	}

	TreeNode *get_root() { return this->root; }
};

// λ����
class CBTInserter2 {
private:
	int cnt = 0;
	TreeNode *root;

public:
	CBTInserter2(TreeNode *root) {
		this->root = root;
		queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			++cnt;
			TreeNode *temp = q.front();
			q.pop();
			if (temp->left) q.push(temp->left);
			if (temp->right) q.push(temp->right);
		}
	}

	int insert(int val) {
		++cnt;
		TreeNode *child = new TreeNode(val);
		TreeNode *node = this->root;

		// ��ȡ���λ1��λ��
		int msb_i = log2(cnt);
		// �����λ1��Ϊ0
		int dir = cnt & ~(1 << msb_i);
		for (int i = msb_i - 1; i > 0; --i) {
			if (dir & (1 << i)) node = node->right;
			else node = node->left;
		}
		if (cnt & 1) node->right = child;
		else node->left = child;
		return node->val;
	}

	TreeNode *get_root() { return this->root; }
};
/*
* https://leetcode.cn/problems/complete-binary-tree-inserter/solutions/1689234/wan-quan-er-cha-shu-cha-ru-qi-by-leetcod-lf8t/
* @author ���۹ٷ����
*/

/**
* Your CBTInserter object will be instantiated and called as such:
* CBTInserter* obj = new CBTInserter(root);
* int param_1 = obj->insert(val);
* TreeNode* param_2 = obj->get_root();
*/