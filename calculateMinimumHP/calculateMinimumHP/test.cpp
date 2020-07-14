#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int n = dungeon.size();
		int m = dungeon[0].size();
		vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
		dp[n][m - 1] = dp[n - 1][m] = 1;
		for (int i = n - 1; i >= 0; i--)
		{
			for (int j = m - 1; j >= 0; j--)
			{
				int _min = min(dp[i + 1][j], dp[i][j + 1]);
				dp[i][j] = max(_min - dungeon[i][j], 1);
			}
		}
		return dp[0][0];
	}
};

int main()
{
	vector<vector<int>> nums{ {-2,-3,3},{-5,-10,1},{10,30,-5} };
	cout << Solution().calculateMinimumHP(nums) << endl;
	return 0;
}