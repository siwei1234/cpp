#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int tribonacci(int n) {
		if (n == 0)
			return 0;
		if (n <= 2)
			return 1;
		vector<int> dp(n + 1, 0);
		dp[1] = 1, dp[2] = 1;
		for (int i = 3; i <= n; i++)
		{
			dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];
		}
		return dp[n];
	}
};

int main()
{
	cout << Solution().tribonacci(10) << endl;
	return 0;
}