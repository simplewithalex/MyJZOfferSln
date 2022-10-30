#include "header.h"

/*

����һ�� 24 Сʱ�ƣ�Сʱ:���� "HH:MM"����ʱ���б��ҳ��б�����������ʱ�����Сʱ���Է�������ʾ��

ʾ�� 1��
���룺timePoints = ["23:59","00:00"]
�����1

ʾ�� 2��
���룺timePoints = ["00:00","23:59","00:00"]
�����0

��ʾ��
2 <= timePoints.length <= 2 * 10^4
timePoints[i] ��ʽΪ "HH:MM"

ע�⣺��������վ 539 ����ͬ�� https://leetcode-cn.com/problems/minimum-time-difference/

*/

class Solution1 {
private:
	int getMinutes(const string &t) {
		return ((t[0] - '0') * 10 + t[1] - '0') * 60 + (t[3] - '0') * 10 + t[4] - '0';
	}

public:
	int findMinDifference(vector<string> &timePoints) {
		sort(timePoints.begin(), timePoints.end());
		int res = INT_MAX;
		int t0 = getMinutes(timePoints[0]);
		int pre = t0;
		for (int i = 1; i < timePoints.size(); ++i) {
			int ti = getMinutes(timePoints[i]);
			res = min(ti - pre, res);
			pre = ti;
		}
		res = min(t0 + 1440 - pre, res);
		return res;
	}
};


class Solution2 {
private:
	int getMinutes(const string &t) {
		return ((t[0] - '0') * 10 + t[1] - '0') * 60 + (t[3] - '0') * 10 + t[4] - '0';
	}

public:
	int findMinDifference(vector<string> &timePoints) {
		int n = timePoints.size();
		if (n > 1440) return 0;
		vector<int> cnts(1440 * 2, 0);
		for (const auto &t : timePoints) {
			int ti = getMinutes(t);
			++cnts[ti], ++cnts[ti + 1440];
		}
		int res = 1440, pre = -1;
		for (int i = 0; i < 1440 * 2 && res != 0; ++i) {
			if (cnts[i] == 0) continue;
			else if (cnts[i] > 1) res = 0;
			else if (pre != -1) res = min(i - pre, res);
			pre = i;
		}
		return res;
	}
};
/*
 * https://leetcode.cn/problems/minimum-time-difference/solutions/1217545/gong-shui-san-xie-jian-dan-mo-ni-ti-by-a-eygg/
 * @author https://leetcode.cn/u/ac_oier/
 */