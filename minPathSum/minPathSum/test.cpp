#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.size() == 0 || grid[0].size() == 0)
			return 0;
		int n = grid.size(), m = grid[0].size();
		vector<vector<int>> dp(n, vector<int>(m));
		dp[0][0] = grid[0][0];
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = dp[i - 1][0] + grid[i][0];
		}
		for (int i = 1; i < m; i++)
		{
			dp[0][i] = dp[0][i - 1] + grid[0][i];
		}
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
			}
		}
		return dp[n - 1][m - 1];
	}
};
int main()
{

	vector<vector<int>> nums = { {1,3,1 }, {1,5,1},{4,2,1 } };
	cout << Solution().minPathSum(nums) << endl;
	return 0;
}