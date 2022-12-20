#include "header.h"

/*

����һ���������� nums ���������� k �� t ��
�����ж��Ƿ����������ͬ�±� i �� j��ʹ�� abs(nums[i] - nums[j]) <= t ��ͬʱ������ abs(i - j) <= k ��
��������򷵻� true�������ڷ��� false��

ʾ�� 1��
���룺nums = [1,2,3,1], k = 3, t = 0
�����true

ʾ�� 2��
���룺nums = [1,0,1,1], k = 1, t = 2
�����true

ʾ�� 3��
���룺nums = [1,5,9,1,5,9], k = 2, t = 3
�����false

��ʾ��
0 <= nums.length <= 2 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
0 <= k <= 10^4
0 <= t <= 2^31 - 1

ע�⣺��������վ 220 ����ͬ�� https://leetcode-cn.com/problems/contains-duplicate-iii/

*/

// �������� + ���򼯺�
class Solution1 {
public:
	bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
		int len = nums.size();
		set<int> s;
		for (int i = 0; i < nums.size(); ++i) {
			auto it = s.lower_bound(max(nums[i], INT_MIN + t) - t);
			if (it != s.end() && *it <= (min(nums[i], INT_MAX - t) + t)) return true;
			s.insert(nums[i]);
			if (s.size() == k + 1) s.erase(nums[i - k]);
		}
		return false;
	}
};
/**
 * �������⣬ʵ���Ͽ������Ϊ��������ͬԪ�ص��±���벻����k�� Ԫ��ֵ�Ĳ����t��
 * ��Ȼ��Ŀ��ʹ���˾���ֵ����ʾ���������ϻ���������ͬԪ�أ����ǻ�Ϊi��j��
 * ��j���ӽ�ȥ�������i����������ʱ Vj Ҳ���� Vi (+/-) t������i��j��ɴ�j���ӽǿ�ǰ���i�����һ����
 * ����ֻ�������е�һ�����򼴿ɡ�
 *
 * https://leetcode.cn/problems/contains-duplicate-iii/solutions/726619/cun-zai-zhong-fu-yuan-su-iii-by-leetcode-bbkt/
 * @author https://leetcode.cn/u/leetcode-solution/
 */


// Ͱ����
class Solution2 {
private:
	int getID(long long n, long long m) {
		return n < 0 ? (n + 1) / m - 1 : n / m;
	}

public:
	bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
		unordered_map<int, int> mp;
		int len = nums.size();
		for (int i = 0; i < len; ++i) {
			long long n = nums[i];
			int id = getID(n, t + 1LL);
			if (mp.count(id)) return true;
			if (mp.count(id - 1) && abs(n - mp[id - 1]) <= t) return true;
			if (mp.count(id + 1) && abs(n - mp[id + 1]) <= t) return true;
			mp[id] = n;
			if (mp.size() == k + 1) mp.erase(getID(nums[i - k], t + 1LL));
		}
		return false;
	}
};
/**
 * getID �������߼��ɲο�
 * https://leetcode.cn/problems/contains-duplicate-iii/solutions/726905/gong-shui-san-xie-yi-ti-shuang-jie-hua-d-dlnv/
 * @author https://leetcode.cn/u/ac_oier/
 */