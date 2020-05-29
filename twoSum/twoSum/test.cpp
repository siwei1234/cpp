#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<double> twoSum(int n) {
		int dp[15][70];
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= 6; i++)
			dp[1][i] = 1;
		for (int i = 2; i <= n; i++)
		{
			for (int j = i; j <= 6 * i; j++)
			{
				for (int k = 1; k <= 6; k++)
				{
					if (j - k <= 0)
						break;
					dp[i][j] += dp[i - 1][j - k];
				}
			}
		}
		int all = pow(6, n);
		vector<double> ret;
		for (int i = n; i <= 6 * n; i++)
		{
			ret.push_back(dp[n][i] * 1.0 / all);
		}
		return ret;
	}
};

int main()
{
	vector<double> ret = Solution().twoSum(2);
	for (auto e : ret)
	{
		cout << e;
	}
	return 0;
}