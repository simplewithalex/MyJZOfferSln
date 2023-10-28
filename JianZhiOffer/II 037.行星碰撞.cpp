#include "header.h"

/*

LCR 037. ������ײ


����һ���������� asteroids����ʾ��ͬһ�е�С����

���������е�ÿһ��Ԫ�أ������ֵ��ʾС���ǵĴ�С��������ʾС���ǵ��ƶ���������ʾ�����ƶ�������ʾ�����ƶ���

ÿһ��С��������ͬ���ٶ��ƶ����ҳ���ײ��ʣ�µ�����С����

��ײ��������С�����໥��ײ����С��С���ǻᱬը���������С���Ǵ�С��ͬ��������С���Ƕ��ᱬը�������ƶ�������ͬ��С���ǣ���Զ���ᷢ����ײ

ʾ�� 1��
���룺asteroids = [5,10,-5]
�����[5,10]
���ͣ�10 �� -5 ��ײ��ֻʣ�� 10 �� 5 �� 10 ��Զ���ᷢ����ײ��

ʾ�� 2��
���룺asteroids = [8,-8]
�����[]
���ͣ�8 �� -8 ��ײ�����߶�������ը��

ʾ�� 3��
���룺asteroids = [10,2,-5]
�����[10]
���ͣ�2 �� -5 ������ײ��ʣ�� -5��10 �� -5 ������ײ��ʣ�� 10


��ʾ��
2 <= asteroids.length <= 10^4
-1000 <= asteroids[i] <= 1000
asteroids[i] != 0

ע�⣺��������վ 735 ����ͬ�� https://leetcode-cn.com/problems/asteroid-collision/

*/

class Solution {
public:
	vector<int> asteroidCollision(vector<int> &asteroids) {
		vector<int> st;
		for (const auto &aster : asteroids) {
			bool alive = true;
			while (alive && aster < 0 && !st.empty() && st.back() > 0) {
				alive = st.back() < abs(aster);
				if (st.back() <= abs(aster)) st.pop_back();
			}
			if (alive) st.push_back(aster);
		}
		return st;
	}
};
