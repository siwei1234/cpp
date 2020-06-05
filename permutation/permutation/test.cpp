#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<string> permutation(string s) {
		if (s.empty())
			return {};
		::sort(s.begin(), s.end());
		vector<string>ret;
		vector<bool>judge(s.size(), false);
		string track;
		backtrack(ret, s, track, judge);
		return ret;
	}
	void backtrack(vector<string>& ret, string s, string track, vector<bool>& judge)
	{
		if (track.size() == s.size())
		{
			ret.push_back(track);
			return;
		}
		for (int i = 0; i < s.size(); i++)
		{
			if (judge[i])
				continue;
			if (i > 0 && !judge[i - 1] && s[i - 1] == s[i])
				continue;
			judge[i] = true;
			track += s[i];
			backtrack(ret, s, track, judge);
			track.pop_back();
			judge[i] = false;
		}

	}
};

int main()
{
	string s("abc");
	vector<string>ret = Solution().permutation(s);
	for(auto e : ret)
	{
		cout << e << endl;
	}
	return 0;
}