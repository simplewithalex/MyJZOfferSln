#include "header.h"

/*

��ָ Offer II 109. ��������

����һ�������ĸ�Բ�β��ֵ�ת������ÿ�����ֶ���10�����֣� '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'
ÿ�����ֿ���������ת������� '9' ��Ϊ '0'��'0' ��Ϊ '9'
ÿ����ת��ֻ����תһ�����ֵ�һλ����

���ĳ�ʼ����Ϊ '0000' ��һ�������ĸ����ֵ����ֵ��ַ���

�б� deadends ������һ���������֣�һ�����ֵ����ֺ��б�����κ�һ��Ԫ����ͬ����������ᱻ�����������޷��ٱ���ת

�ַ��� target ������Խ��������֣�����Ҫ����������Ҫ����С��ת���������������β��ܽ��������� -1

ʾ�� 1:
���룺deadends = ["0201","0101","0102","1212","2002"], target = "0202"
�����6
���ͣ�
���ܵ��ƶ�����Ϊ "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"��
ע�� "0000" -> "0001" -> "0002" -> "0102" -> "0202" �����������ǲ��ܽ����ģ�
��Ϊ�������� "0102" ʱ������ͻᱻ������

ʾ�� 2:
����: deadends = ["8888"], target = "0009"
�����1
���ͣ������һλ������תһ�μ��� "0000" -> "0009"��

ʾ�� 3:
����: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
�����-1
���ͣ��޷���ת��Ŀ�������Ҳ���������

��ʾ��
1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target ���� deadends ֮��
target �� deadends[i] ��������λ�������

ע�⣺��������վ 752 ����ͬ�� https://leetcode-cn.com/problems/open-the-lock/

*/

// ˫��BFS���ο� II 108. �����ݱ�
class Solution {
public:
	int openLock(vector<string> &deadends, string target) {
		unordered_set<string> dict(deadends.begin(), deadends.end());
		unordered_set<string> head, tail;
		if (dict.count("0000")) return -1;
		if (target == "0000") return 0;
		head.insert("0000");
		tail.insert(target);
		int ladder = 1;
		while (!head.empty() && !tail.empty()) {
			if (head.size() > tail.size()) swap(head, tail);
			unordered_set<string> tmpset;
			for (string word : head) {
				for (int i = 0; i < word.size(); ++i) {
					char c = word[i];
					word[i] = c == '9' ? '0' : c + 1;
					if (tail.count(word)) return ladder;
					if (!dict.count(word)) {
						tmpset.insert(word);
						dict.insert(word);
					}
					word[i] = c == '0' ? '9' : c - 1;
					if (tail.count(word)) return ladder;
					if (!dict.count(word)) {
						tmpset.insert(word);
						dict.insert(word);
					}
					word[i] = c;
				}
			}
			++ladder;
			swap(head, tmpset);
		}
		return -1;
	}
};

// https://leetcode.com/problems/open-the-lock/solutions/110237/regular-java-bfs-solution-and-2-end-bfs-solution-with-improvement/
// @author https://leetcode.com/yaoyimingg/
