#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int n = cost.size();
		vector<int> dp(n + 1, 0);
		for (int i = 2; i <= n; i++)
		{
			dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
		}
		return dp[n];
	}
};

int main()
{
	vector<int> nums = { 1, 100, 1, 1, 1, 100, 1, 1, 100, 1 };
	cout << Solution().minCostClimbingStairs(nums) << endl;
	return 0;
}