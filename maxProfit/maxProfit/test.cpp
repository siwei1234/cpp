#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.empty())
			return 0;
		int n = prices.size();
		vector<vector<int>> dp(n, vector<int>(3));
		dp[0][0] = -prices[0];
		for (int i = 1; i < n; i++)
		{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
			dp[i][1] = dp[i - 1][0] + prices[i];
			dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
		}
		return max(dp[n - 1][1], dp[n - 1][2]);
	}
};

int main()
{
	vector<int> nums{ 1,2,3,0,2 };
	cout << Solution().maxProfit(nums) << endl;
	return 0;
}