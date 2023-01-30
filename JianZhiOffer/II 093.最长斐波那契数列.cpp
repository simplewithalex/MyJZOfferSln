#include "header.h"

/*

��ָ Offer II 093. �쳲���������

������� X_1, X_2, ..., X_n ����������������˵����쳲�����ʽ�ģ�
1. n >= 3
2. �������� i + 2 <= n������ X_i + X_{i+1} = X_{i+2}
����һ���ϸ�����������������γ����� arr ���ҵ� arr �����쳲�����ʽ�������еĳ��ȡ����һ�������ڣ����� 0
������һ�£��������Ǵ�ԭ���� arr �����������ģ����� arr ��ɾ������������Ԫ�أ�Ҳ���Բ�ɾ���������ı�����Ԫ�ص�˳�����磬 [3, 5, 8] �� [3, 4, 5, 6, 7, 8] ��һ�������У�

ʾ�� 1��
����: arr = [1,2,3,4,5,6,7,8]
���: 5
����: ���쳲�����ʽ������Ϊ [1,2,3,5,8] ��

ʾ�� 2��
����: arr = [1,3,7,11,12,14,18]
���: 3
����: ���쳲�����ʽ�������� [1,11,12]��[3,11,14] �Լ� [7,11,18] ��

��ʾ��
3 <= arr.length <= 1000
1 <= arr[i] < arr[i + 1] <= 10^9

ע�⣺��������վ 873 ����ͬ�� https://leetcode-cn.com/problems/length-of-longest-fibonacci-subsequence/

*/

// ����¼
class Solution1 {
public:
	int lenLongestFibSubseq(vector<int> &arr) {
		int len = arr.size();
		vector<vector<int>> memo(len, vector<int>(len, -1));
		unordered_map<int, int> mp;
		for (int i = 0; i < arr.size(); ++i) mp[arr[i]] = i;
		int ans = 0;
		for (int i = 2; i < len; ++i) {
			for (int j = i - 1; j > 0; --j) {
				ans = max(ans, solve(arr, j, i, memo, mp));
			}
		}
		return ans < 3 ? 0 : ans;
	}

private:
	int solve(vector<int> &arr, int j, int i, vector<vector<int>> &memo,
		unordered_map<int, int> &mp) {
		int k = arr[i] - arr[j];
		if (!mp.count(k) || mp[k] >= j) return 0;
		if (memo[j][i] != -1) return memo[j][i];
		return memo[j][i] = max(1 + solve(arr, mp[k], j, memo, mp), 3);
	}
};

