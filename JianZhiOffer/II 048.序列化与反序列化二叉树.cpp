#include "header.h"

/*

���л��ǽ�һ�����ݽṹ���߶���ת��Ϊ�����ı���λ�Ĳ������������Խ�ת��������ݴ洢��һ���ļ������ڴ��У�ͬʱҲ����ͨ�����紫�䵽��һ���������������ȡ�෴��ʽ�ع��õ�ԭ���ݡ�
�����һ���㷨��ʵ�ֶ����������л��뷴���л������ﲻ�޶��������/�����л��㷨ִ���߼�����ֻ��Ҫ��֤һ�����������Ա����л�Ϊһ���ַ������ҽ�����ַ��������л�Ϊԭʼ�����ṹ��
��ʾ: ���������ʽ�� LeetCode Ŀǰʹ�õķ�ʽһ�£���������� LeetCode ���л��������ĸ�ʽ���㲢�Ǳ����ȡ���ַ�ʽ����Ҳ���Բ��������ķ������������⡣


ʾ�� 1��
���룺root = [1,2,3,null,null,4,5]
�����[1,2,3,null,null,4,5]

ʾ�� 2��
���룺root = []
�����[]

ʾ�� 3��
���룺root = [1]
�����[1]

ʾ�� 4��
���룺root = [1,2]
�����[1,2]

��ʾ��
���н�����ڷ�Χ[0, 10^4]��
-1000 <= Node.val <= 1000

ע�⣺��������վ 297 ����ͬ��https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/

*/

class Codec {
public:
	// Encodes a tree to a single string.
	string serialize(TreeNode *root) {
		ostringstream out;
		serial(root, out);
		return out.str();
	}

	// Decodes your encoded data to tree.
	TreeNode *deserialize(string data) {
		istringstream in(data);
		return deserial(in);
	}

private:
	void serial(TreeNode *node, ostringstream &out) {
		if (!node) {
			out << "#,";
			return;
		}
		out << node->val << ",";
		serial(node->left, out);
		serial(node->right, out);
	}

	TreeNode *deserial(istringstream &in) {
		string val;
		getline(in, val, ',');
		if (val == "#") return nullptr;
		TreeNode *node = new TreeNode(stoi(val));
		node->left = deserial(in);
		node->right = deserial(in);
		return node;
	}
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));