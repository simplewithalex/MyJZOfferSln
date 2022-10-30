#include "header.h"

/*

����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�
��ĸ��λ��������������Դ���ʵ���ĸ�õ���һ���µ��ʣ�����Դ�����е���ĸͨ��ǡ��ֻ��һ�Ρ�

ʾ�� 1:
����: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
���: [["bat"],["nat","tan"],["ate","eat","tea"]]

ʾ�� 2:
����: strs = [""]
���: [[""]]

ʾ�� 3:
����: strs = ["a"]
���: [["a"]]

��ʾ��
1 <= strs.length <= 10^4
0 <= strs[i].length <= 100
strs[i] ������Сд��ĸ

ע�⣺��������վ 49 ����ͬ�� https://leetcode-cn.com/problems/group-anagrams/


*/

class Solution1 {
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs) {
		unordered_map<string, vector<string>> m;
		for (const auto &str : strs) {
			string key = str;
			sort(key.begin(), key.end());
			m[key].push_back(str);
		}
		vector<vector<string>> res;
		for (auto it = m.begin(); it != m.end(); ++it) {
			res.push_back(it->second);
		}
		return res;
	}
};

class Solution2 {
public:
	vector<vector<string>> groupAnagrams(vector<string> &strs) {

		/*
		* A capture with an initializer acts as if it declares and explicitly captures a variable declared with type auto,
		* whose declarative region is the body of the lambda expression
		* https://en.cppreference.com/w/cpp/language/lambda#Lambda_capture
		*/
		auto arrayHash = [fn = hash<int>()](const array<int, 26> &arr)->size_t {
			return accumulate(arr.begin(), arr.end(), (size_t)0,
				[&](size_t acc, int num) { return (acc << 1) ^ fn(num); });
		};

		unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> m(0, arrayHash);
		for (const auto &str : strs) {
			array<int, 26> arr{};
			for (int i = 0; i < str.size(); ++i) ++arr[str[i] - 'a'];
			m[arr].push_back(str);
		}
		vector<vector<string>> res;
		for (auto it = m.begin(); it != m.end(); ++it) res.push_back(it->second);
		return res;
	}
};
/*
* https://leetcode.cn/problems/group-anagrams/solutions/520469/zi-mu-yi-wei-ci-fen-zu-by-leetcode-solut-gyoc/comments/1579184
* @author ���۹ٷ����
*/


