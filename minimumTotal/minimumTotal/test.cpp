#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int n = triangle.size();
		vector<vector<int>> dp(n, vector<int>(n));
		dp[0][0] = triangle[0][0];
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = dp[i - 1][0] + triangle[i][0];
			for (int j = 1; j < i; j++)
			{
				dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
			}
			dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
		}
		int ret = dp[n - 1][0];
		for (int i = 1; i < n; i++)
		{
			if (ret > dp[n - 1][i])
				ret = dp[n - 1][i];
		}
		return ret;
	}
};

int main()
{
	vector<vector<int>> nums{ {2}, {3, 4},{6,5,7},{4,1,8,3 } };
	cout << Solution().minimumTotal(nums) << endl;
	return 0;
}