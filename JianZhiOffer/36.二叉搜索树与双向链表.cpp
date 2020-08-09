#include "header.h"

/*

����һ�ö��������������ö���������ת����һ�������ѭ��˫������Ҫ���ܴ����κ��µĽڵ㣬ֻ�ܵ������нڵ�ָ���ָ��
����ϣ��������������ת��Ϊ˫��ѭ�����������е�ÿ���ڵ㶼��һ��ǰ���ͺ��ָ�롣����˫��ѭ��������һ���ڵ��ǰ�������һ���ڵ㣬���һ���ڵ�ĺ���ǵ�һ���ڵ㡣
�ر�أ�����ϣ�����Ծ͵����ת����������ת������Ժ����нڵ����ָ����Ҫָ��ǰ�������нڵ����ָ����Ҫָ���̡�����Ҫ���������еĵ�һ���ڵ��ָ�롣

ע�⣺��������վ 426 ����ͬ��https://leetcode-cn.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/
ע�⣺����Ա�ԭ���иĶ���

*/

// Definition for a Node.
class Node 
{
public:
	int val;
	Node *left;
	Node *right;

	Node() {}

	Node(int _val) 
	{
		val = _val;
		left = NULL;
		right = NULL;
	}

	Node(int _val, Node *_left, Node *_right) 
	{
		val = _val;
		left = _left;
		right = _right;
	}
};

//lastNode��Ϊ���ã�ʼ�հ󶨸�ָ���������ס��һ����������Ľڵ�
class Solution {
public:
	Node * treeToDoublyList(Node *root)
	{
		if (!root) return nullptr;
		Node *node = root;
		Node *lastNode = nullptr;
		travIn(node, lastNode);
		while (node->left) node = node->left;
		node->left = lastNode;
		lastNode->right = node;
		return node;
	}
	void travIn(Node *node, Node *&lastNode)
	{
		if (!node) return;
		travIn(node->left, lastNode);
		node->left = lastNode;
		if (lastNode) lastNode->right = node;
		lastNode = node;
		travIn(node->right, lastNode);
	}
};