#include "header.h"

/*

LCR 038. ÿ���¶�

����һ���������� temperatures ����ʾÿ����¶ȣ�����һ������ answer
���� answer[i] ��ָ���ڵ� i �죬��һ�������¶ȳ����ڼ����
�����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档

ʾ�� 1:
����: temperatures = [73,74,75,71,69,72,76,73]
���: [1,1,4,2,1,1,0,0]

ʾ�� 2:
����: temperatures = [30,40,50,60]
���: [1,1,1,0]

ʾ�� 3:
����: temperatures = [30,60,90]
���: [1,1,0]

��ʾ��
1 <= temperatures.length <= 10^5
30 <= temperatures[i] <= 100

ע�⣺��������վ 739 ����ͬ�� https://leetcode-cn.com/problems/daily-temperatures/

*/

// ����ջ
class Solution {
public:
	vector<int> dailyTemperatures(vector<int> &temperatures) {
		int len = temperatures.size();
		vector<int> ans(len);
		stack<int> s;
		for (int i = 0; i < len; ++i) {
			while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
				int preIdx = s.top();
				s.pop();
				ans[preIdx] = i - preIdx;
			}
			s.push(i);
		}
		return ans;
	}
};
