#include "header.h"

/*

����һ���Ѱ��� �������� ���������� numbers ��������������ҳ��������������֮�͵���Ŀ���� target
����Ӧ���Գ���Ϊ 2 �������������ʽ���������������±�ֵ��numbers ���±�� 0 ��ʼ���� �����Դ�����Ӧ������ 0 <= answer[0] < answer[1] < numbers.length
���������д�����ֻ����һ�Է������������֣�ͬʱһ�����ֲ���ʹ�����Ρ�

ʾ�� 1��
���룺numbers = [1,2,4,6,10], target = 8
�����[1,3]
���ͣ�2 �� 6 ֮�͵���Ŀ���� 8 ����� index1 = 1, index2 = 3 ��

ʾ�� 2��
���룺numbers = [2,3,4], target = 6
�����[0,2]

ʾ�� 3��
���룺numbers = [-1,0], target = -1
�����[0,1]

��ʾ��
2 <= numbers.length <= 3 * 10^4
-1000 <= numbers[i] <= 1000
numbers �� ����˳�� ����
-1000 <= target <= 1000
������һ����Ч��

ע�⣺��������վ 167 �����ƣ��±���㲻ͬ����https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/

*/

// ���ֲ���
class Solution1 {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		for (int i = 0; i < numbers.size(); ++i) {
			// �̶�iԪ�أ������Ҳ���ֲ�����һ����
			int lo = i + 1, hi = numbers.size() - 1;
			while (lo < hi) {
				int mi = lo + (hi - lo) / 2;
				if (numbers[i] + numbers[mi] < target) lo = mi + 1;
				else hi = mi;
			}
			if (numbers[i] + numbers[lo] == target) return{ i, lo };
		}
		return{ -1, -1 };
	}
};

// ˫ָ��
class Solution2 {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		int lo = 0, hi = numbers.size() - 1;
		while (lo < hi) {
			int sum = numbers[lo] + numbers[hi];
			if (sum == target) return{ lo, hi };
			else if (sum < target) ++lo;
			else --hi;
		}
		return{ -1, -1 };
	}
};
