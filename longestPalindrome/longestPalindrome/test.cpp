#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<string>
using namespace std;


class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		vector<vector<int>> dp(len, vector<int>(len));
		string ret;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j + i < len; j++)
			{
				int k = j + i;
				if (i == 0)
					dp[j][k] = 1;
				else if (i == 1)
					dp[j][k] = (s[j] == s[k]);
				else
					dp[j][k] = (s[j] == s[k] && dp[j + 1][k - 1]);
				if (dp[j][k] && i + 1 > ret.size())
					ret = s.substr(j, i + 1);
			}
		}
		return ret;
	}
};
int main()
{
	string s("babad");
	cout << Solution().longestPalindrome(s) << endl;
	return 0;
}