#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	/**
	 *
	 * @param m int����
	 * @param n int����
	 * @return int����
	 */
	int uniquePaths(int m, int n) {
		// write code here
		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			dp[i][0] = 1;
		}
		for (int i = 0; i < n; i++)
		{
			dp[0][i] = 1;
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return dp[m - 1][n - 1];
	}
};


int main()
{
	cout << Solution().uniquePaths(2, 3) << endl;
	return 0;
}