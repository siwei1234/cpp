#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;


class Solution {
public:
	/**
	 *
	 * @param word1 string×Ö·û´®
	 * @param word2 string×Ö·û´®
	 * @return intÕûÐÍ
	 */
	int minDistance(string word1, string word2) {
		// write code here
		if (word1.empty() || word2.empty())
			return max(word1.size(), word2.size());
		int len1 = word1.size();
		int len2 = word2.size();
		vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
		for (int i = 0; i <= len1; i++)
		{
			dp[i][0] = i;
		}
		for (int i = 0; i <= len2; i++)
		{
			dp[0][i] = i;
		}

		for (int i = 1; i <= len1; i++)
		{
			for (int j = 1; j <= len2; j++)
			{
				if (word1[i - 1] == word2[j - 1])
				{
					dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = min(dp[i - 1][j - 1], dp[i][j]);
				}
				else
				{
					dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
					dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
				}
			}
		}
		return dp[len1][len2];
	}
};

int main()
{
	string word1 = "abcd";
	string word2 = "abed";
	cout << Solution().minDistance(word1, word2) << endl;

	return 0;
}