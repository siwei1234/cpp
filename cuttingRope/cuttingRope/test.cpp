#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
	int cuttingRope(int n) {
		if (n == 2)
			return 1;
		if (n == 3)
			return 2;
		vector<int> dp(n + 1);
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 3;
		for (int i = 4; i <= n; i++)
		{
			int maxval = 0;
			for (int j = 1; j <= i / 2; j++)
			{
				maxval = max(maxval, dp[j] * dp[i - j]);
			}
			dp[i] = maxval;
		}
		return dp[n];
	}
};

int main()
{
	cout << Solution().cuttingRope(12) << endl;
	return 0;
}