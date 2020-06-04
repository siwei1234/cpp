#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
	void recall(vector<string>& s, vector<string>& ret, string tmp, int index)
	{
		if (index == s.size())
		{
			ret.push_back(tmp);
			return;
		}
		string tmp1;
		for (auto e : s[index])
		{
			tmp1 = tmp + e;
			recall(s, ret, tmp1, index + 1);
		}
	}
	vector<string> letterCombinations(string digits) {
		if (digits.size() == 0)
			return {};
		vector<string> bot{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		vector<string> s, ret;
		for (auto e : digits)
			s.push_back(bot[e - '2']);
		string tmp;
		recall(s, ret, tmp, 0);
		return ret;
	}
};

int main()
{
	string s("23");
	vector<string> ret = Solution().letterCombinations(s);
	for (auto e : ret)
	{
		cout << e << endl;
	}
	return 0;
}