#include "header.h"

/*

LCR 068. ��������λ��

����һ�����������һ��Ŀ��ֵ�����������ҵ�Ŀ��ֵ�������������������Ŀ��ֵ�������������У����������ᱻ��˳������λ�á�

�����ʹ��ʱ�临�Ӷ�Ϊ O(log n) ���㷨

ʾ�� 1:
����: nums = [1,3,5,6], target = 5
���: 2

ʾ�� 2:
����: nums = [1,3,5,6], target = 2
���: 1

ʾ�� 3:
����: nums = [1,3,5,6], target = 7
���: 4

��ʾ:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums Ϊ ���ظ�Ԫ�� �� ���� ��������
-10^4 <= target <= 10^4

ע�⣺��������վ 35 ����ͬ�� https://leetcode-cn.com/problems/search-insert-position/


*/

class Solution {
public:
	int searchInsert(vector<int> &nums, int target) {
		int len = nums.size();
		int lo = 0, hi = len;
		// ������ nums[lo ... hi] �������� 1 �����ڵ��� target ��Ԫ���±�
		while (lo < hi) {
			int mi = lo + (hi - lo) / 2;
			nums[mi] < target ? lo = mi + 1 : hi = mi;
		}
		return lo;
	}
};
/*

��� 1�������ǰ mid ��������ֵ�ϸ�С�� target����ô mid �Լ� mid ��ߵ�����Ԫ�ؾ�һ�����ǡ�����Ԫ�ص�λ�á���
�����һ������������ [mid + 1 ... hi]����һ�ְ� lo �ƶ��� mid + 1 λ�ã�������� lo = mid + 1��

��� 2��������� mid ��������ֵ���ڵ��� target����ô mid �����ǡ�����Ԫ�ص�λ�á���mid ���ұ�һ�����ǡ�����Ԫ�ص�λ�á���
��� mid ����߲����ڡ�����Ԫ�ص�λ�á������ǲſ���˵ mid �ǡ�����Ԫ�ص�λ�á���
�����һ������������ [lo ... mid]����һ�ְ� hi �ƶ��� mid λ�ã�������� hi = mid��

*/

// https://leetcode.cn/problems/search-insert-position/solutions/10969/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/
// @author https://leetcode.cn/u/liweiwei1419/

