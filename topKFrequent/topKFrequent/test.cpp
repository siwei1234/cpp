#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
	vector<string> topKFrequent(vector<string>& words, int k) {
		map<string, int> m;
		for (auto& e : words)
		{
			m[e]++;
		}

		multimap<int, string, greater<int>> mm;
		for (auto& e : m)
		{
			mm.insert(make_pair(e.second, e.first));
		}

		vector<string> ret;
		for (auto e : mm)
		{
			ret.push_back(e.second);
			if (--k == 0)
				break;
		}
		return ret;
	}
};
int main()
{
	vector<string> words = { "i", "love", "leetcode", "i", "love", "coding" };
	vector<string> ret = Solution().topKFrequent(words, 2);
	for (auto& e : ret)
	{
		cout << e << endl;
	}
	return 0;
}