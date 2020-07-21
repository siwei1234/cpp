#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
#include<set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, vector<string>& wordDict) {
		set<string> se;
		for (auto e : wordDict)
			se.insert(e);
		vector<bool> dp(s.size() + 1);
		dp[0] = true;
		for (int i = 0; i <= s.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (dp[j] && se.find(s.substr(j, i - j)) != se.end())
				{
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.size()];
	}
};


int main()
{
	string s = "catsandog";
	vector<string> wordDict = { "cats", "dog", "sand", "and", "cat" };
	cout << Solution().wordBreak(s, wordDict) << endl;
	return 0;
}