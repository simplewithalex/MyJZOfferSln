#include "header.h"

/*

LCR 073. �����㽶������

����ϲ�����㽶�������� n ���㽶���� i ������ piles[i] ���㽶�������Ѿ��뿪�ˣ����� h Сʱ�����
������Ծ��������㽶���ٶ� k����λ����/Сʱ����ÿ��Сʱ��������ѡ��һ���㽶�����гԵ� k �����������㽶���� k ���������Ե���ѵ������㽶��Ȼ����һСʱ�ڲ����ٳԸ�����㽶
����ϲ�������ԣ�����Ȼ���ھ�������ǰ�Ե����е��㽶

������������ h Сʱ�ڳԵ������㽶����С�ٶ� k��k Ϊ������

ʾ�� 1��
���룺piles = [3,6,7,11], h = 8
�����4

ʾ�� 2��
���룺piles = [30,11,23,4,20], h = 5
�����30

ʾ�� 3��
���룺piles = [30,11,23,4,20], h = 6
�����23

��ʾ��
1 <= piles.length <= 10^4
piles.length <= h <= 10^9
1 <= piles[i] <= 10^9

ע�⣺��������վ 875 ����ͬ�� https://leetcode-cn.com/problems/koko-eating-bananas/


*/

class Solution {
public:
	int minEatingSpeed(vector<int> &piles, int h) {
		int lo = 1, hi = *max_element(piles.begin(), piles.end());
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			getSum(piles, mi) > h ? lo = mi + 1 : hi = mi;
		}
		return lo;
	}

private:
	int getSum(const vector<int> &piles, int k) {
		int sum = 0;
		// ����ȡ��
		for (int pile : piles) sum += (pile + k - 1) / k;
		return sum;
	}
};
