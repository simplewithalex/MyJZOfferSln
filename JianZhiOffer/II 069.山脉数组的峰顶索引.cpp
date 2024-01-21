#include "header.h"

/*

LCR 069. ɽ������ķ嶥����

�����������Ե����� arr ��Ϊɽ������:
arr.length >= 3
���� i��0 < i < arr.length - 1��ʹ��:
arr[0] < arr[1] < ... arr[i-1] < arr[i]
arr[i] > arr[i+1] > ... > arr[arr.length - 1]
������������ɵ�ɽ������ arr���������� arr[0] < arr[1] < ... arr[i - 1] < arr[i] > arr[i + 1] > ... > arr[arr.length - 1] ���±� i

�������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(log(n)) �Ľ��������

ʾ�� 1��
���룺arr = [0,1,0]
�����1

ʾ�� 2��
���룺arr = [0,2,1,0]
�����1

ʾ�� 3��
���룺arr = [0,10,5,2]
�����1

��ʾ��
3 <= arr.length <= 10^5
0 <= arr[i] <= 10^6
��Ŀ���ݱ�֤ arr ��һ��ɽ������

ע�⣺��������վ 852 ����ͬ��https://leetcode-cn.com/problems/peak-index-in-a-mountain-array/

*/


class Solution1 {
public:
	int peakIndexInMountainArray(vector<int> &arr) {
		int len = arr.size();
		int lo = 0, hi = len - 1;
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			arr[mi] < arr[mi + 1] ? lo = mi + 1 : hi = mi;
		}
		return lo;
	}
};


// ���ַ�
class Solution2 {
public:
	int peakIndexInMountainArray(vector<int> &arr) {
		int len = arr.size();
		int lo = 0, hi = len - 1;
		while (lo < hi) {
			int m1 = lo + (hi - lo) / 3, m2 = hi - (hi - lo) / 3;
			if (arr[m1] > arr[m2]) hi = m2 - 1;
			else lo = m1 + 1;
		}
		return lo;
	}
};
// https://leetcode.cn/problems/peak-index-in-a-mountain-array/solutions/828434/gong-shui-san-xie-er-fen-san-fen-cha-zhi-5gfv/
// @author https://leetcode.cn/u/ac_oier/

