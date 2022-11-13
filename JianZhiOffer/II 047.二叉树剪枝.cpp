#include "header.h"

/*

����������ĸ����root����������ÿ������ֵҪô��0��Ҫô��1��
�����Ƴ������в�����1��������ԭ��������
�ڵ�node������Ϊnode�����������node�ĺ����

ʾ�� 1��
���룺root = [1,null,0,0,1]
�����[1,null,0,null,1]
���ͣ�
ֻ�к�ɫ�ڵ��������������в����� 1 ������������ͼΪ���صĴ𰸡�

ʾ�� 2��
���룺root = [1,0,1,0,0,0,1]
�����[1,null,1,null,1]

ʾ�� 3��
���룺root = [1,1,0,1,1,0,1,0]
�����[1,1,0,1,1,null,1]

��ʾ��
���нڵ����Ŀ�ڷ�Χ [1, 200] ��
Node.val Ϊ 0 �� 1

ע�⣺��������վ 814 ����ͬ��https://leetcode-cn.com/problems/binary-tree-pruning/

*/

class Solution {
public:
	TreeNode *pruneTree(TreeNode *root) {
		if (!root) return nullptr;
		root->left = pruneTree(root->left);
		root->right = pruneTree(root->right);
		if (!root->left && !root->right && !root->val) return nullptr;
		return root;
	}
};

/**

���Ȿ�������ѣ��������е�һ���ύ�У���Ϊ�Բ�ʹ�õĽڵ�ִ����delete���±���

https://leetcode.cn/problems/pOCWxh/submissions/381722333/

��ɾ��delete�����ύ��ͨ���ˣ����ڽڵ㲻��delete���ٷ�����������۸����۵㣺

https://leetcode.cn/problems/binary-tree-pruning/solutions/1683846/er-cha-shu-jian-zhi-by-leetcode-solution-k336/comments/1663951

Ҳ����˵�ڴ治�������Լ�����ģ���ֻ���õ�һ��ָ���������ǲ���ȥóȻ�ͷ����ġ�ͬʱ����һЩ�������£�

[1] https://www.zhihu.com/question/509145076

[2] https://www.zhihu.com/question/25542360

[3] https://segmentfault.com/q/1010000009987587

*/
