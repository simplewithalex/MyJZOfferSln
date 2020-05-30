#include "header.h"


/*

����ĳ��������ǰ���������������Ľ�������ؽ����ö�������
���������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ������������ء�

*/

struct TreeNode {
	int val;
    TreeNode *left;
	TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin)
	{
		if (pre.empty() || vin.empty()) return nullptr;
		return ConstructCore(pre, 0, vin, 0, vin.size() - 1);
	}
	TreeNode * ConstructCore(vector<int> &pre, int startPre, vector<int> &vin, int startIn, int endIn)
	{
		if (startIn > endIn)
			return nullptr;
		TreeNode *root = new TreeNode(pre[startPre]);
		for (int i = startIn; i <= endIn; ++i)
		{
			if (vin[i] == root->val)
			{
				root->left = ConstructCore(pre, startPre + 1, vin, startIn, i - 1);
				root->right = ConstructCore(pre, i - startIn + startPre + 1, vin, i + 1, endIn);//i-startIn�����������ĳ��ȣ�����i-startIn+startPre+1���������������������㡣
				break;
			}
		}
		return root;
	}
};