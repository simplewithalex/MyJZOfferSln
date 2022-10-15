#include "header.h"

/*

дһ�� RecentCounter ���������ض�ʱ�䷶Χ���������������ʵ�� RecentCounter �ࣺ

1. RecentCounter() ��ʼ����������������Ϊ 0 ��

2. int ping(int t) ��ʱ�� t ���һ������������ t ��ʾ�Ժ���Ϊ��λ��ĳ��ʱ�䣬�����ع�ȥ 3000 �����ڷ��������������������������󣩡�
   ȷ�е�˵�������� [t-3000, t] �ڷ�������������

��֤ ÿ�ζ� ping �ĵ��ö�ʹ�ñ�֮ǰ����� t ֵ��


ʾ�� 1��
���룺
["RecentCounter", "ping", "ping", "ping", "ping"]
[[], [1], [100], [3001], [3002]]
�����
[null, 1, 2, 3, 3]
���ͣ�
RecentCounter recentCounter = new RecentCounter();
recentCounter.ping(1);     // requests = [1]����Χ�� [-2999,1]������ 1
recentCounter.ping(100);   // requests = [1, 100]����Χ�� [-2900,100]������ 2
recentCounter.ping(3001);  // requests = [1, 100, 3001]����Χ�� [1,3001]������ 3
recentCounter.ping(3002);  // requests = [1, 100, 3001, 3002]����Χ�� [2,3002]������ 3

��ʾ��
1 <= t <= 10^9
��֤ÿ�ζ� ping ������ʹ�õ� t ֵ�� �ϸ����
������� ping ���� 10^4 ��

ע�⣺��������վ 933 ����ͬ�� https://leetcode-cn.com/problems/number-of-recent-calls/

*/

class RecentCounter {
private:
	queue<int> q;

public:
	RecentCounter() {}

	int ping(int t) {
		q.push(t);
		while (q.front() < t - 3000) q.pop();
		return q.size();
	}
};

/**
* Your RecentCounter object will be instantiated and called as such:
* RecentCounter* obj = new RecentCounter();
* int param_1 = obj->ping(t);
*/