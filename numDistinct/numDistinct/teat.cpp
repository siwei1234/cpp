
#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
	/**
	 *
	 * @param S string×Ö·û´®
	 * @param T string×Ö·û´®
	 * @return intÕûÐÍ
	 */
	int numDistinct(string S, string T) {
		// write code here
		int s_size = S.size();
		int t_size = T.size();
		if (s_size < t_size)
			return 0;
		if (T.empty())
			return 1;
		vector<vector<int>> dp(s_size + 1, vector<int>(t_size + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i <= s_size; i++)
		{
			dp[i][0] = 1;
			for (int j = 1; j <= t_size; j++)
			{
				if (S[i - 1] == T[j - 1])
				{
					dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		return dp[s_size][t_size];
	}
};

int main()
{
	string s = "rabbbit";
	string t = "rabbit";
	cout << Solution().numDistinct(s, t) << endl;
	return 0;
}