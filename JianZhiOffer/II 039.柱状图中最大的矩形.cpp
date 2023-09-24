#include "header.h"

/*

LCR 039. ��״ͼ�����ľ���

���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1
���ڸ���״ͼ�У��ܹ����ճ����ľ��ε�������

ʾ�� 1:
���룺heights = [2,1,5,6,2,3]
�����10
���ͣ����ľ���Ϊͼ�к�ɫ�������Ϊ 10

ʾ�� 2��
���룺 heights = [2,4]
����� 4

��ʾ��
1 <= heights.length <=10^5
0 <= heights[i] <= 10^4

ע�⣺��������վ 84 ����ͬ�� https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

*/

class Solution {
public:
	int largestRectangleArea(vector<int> &heights) {
		int ans = 0;
		stack<int> s;
		// ͷ���ڱ�
		heights.insert(heights.begin(), 0);
		// β���ڱ�
		heights.push_back(0);
		s.push(0);
		for (int i = 0; i < heights.size(); ++i) {
			while (heights[i] < heights[s.top()]) {
				int cur = s.top();
				s.pop();
				int left = s.top() + 1;
				int right = i - 1;
				ans = max(ans, (right - left + 1) * heights[cur]);
			}
			s.push(i);
		}
		return ans;
	}
};