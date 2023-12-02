#include "header.h"

/*

LCR 067. ��������������������ֵ

����һ���������� nums ������ nums[i] XOR nums[j] ����������������� 0 �� i �� j < n

ʾ�� 1��
���룺nums = [3,10,5,25,2,8]
�����28
���ͣ������������ 5 XOR 25 = 28

ʾ�� 2��
���룺nums = [14,70,53,83,49,91,36,80,92,51,66,70]
�����127


��ʾ��
1 <= nums.length <= 2 * 10^5
0 <= nums[i] <= 2^31 - 1

ע�⣺��������վ 421 ����ͬ�� https://leetcode-cn.com/problems/maximum-xor-of-two-numbers-in-an-array/

*/

struct TrieNode {
	vector<TrieNode *> children;
	TrieNode() : children(2, nullptr) {}
};

class Trie {
private:
	TrieNode *root;

public:
	Trie() { root = new TrieNode(); }

	void insert(int num) {
		TrieNode *cur = root;
		for (int i = 31; i >= 0; --i) {
			char b = (num >> i) & 1;
			if (!cur->children[b]) {
				cur->children[b] = new TrieNode();
			}
			cur = cur->children[b];
		}
	}

	int search(int num) {
		TrieNode *cur = root;
		int ans = 0;
		for (int i = 31; i >= 0; --i) {
			char a = (num >> i) & 1, b = 1 - a;
			if (cur->children[b]) {
				ans |= (b << i);
				cur = cur->children[b];
			} else {
				ans |= (a << i);
				cur = cur->children[a];
			}
		}
		return ans;
	}
};

class Solution {
public:
	int findMaximumXOR(vector<int> &nums) {
		Trie t;
		int ans = 0;
		for (const int &num : nums) {
			t.insert(num);
			int xNum = t.search(num);
			ans = max(ans, num ^ xNum);
		}
		return ans;
	}
};
