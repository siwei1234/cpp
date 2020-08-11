#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
	/**
	 *
	 * @param s string×Ö·û´®
	 * @return intÕûÐÍ
	 */
	bool isPalindrome(string& s, int i, int j)
	{
		while (i < j)
		{
			if (s[i] != s[j])
				return false;
			i++;
			j--;
		}
		return true;
	}
	int minCut(string s) {
		// write code here
		if (s.empty())
			return 0;
		int len = s.size();
		vector<int> dp(len + 1);
		for (int i = 0; i <= len; i++)
			dp[i] = i - 1;
		for (int i = 1; i <= len; i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (isPalindrome(s, j, i - 1))
				{
					dp[i] = min(dp[i], 1 + dp[j]);
				}
			}
		}
		return dp[len];
	}
};


int main()
{
	string s = "aaabbcc";
	cout << Solution().minCut(s) << endl;
	return 0;
}