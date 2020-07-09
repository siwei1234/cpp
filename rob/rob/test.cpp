#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int max(int a, int b)
	{
		return a > b ? a : b;
	}
	int rob(vector<int>& nums) {
		int len = nums.size();
		if (len == 0)
			return 0;
		if (len == 1)
			return nums[0];
		int dp[10];
		dp[1] = nums[0];
		dp[2] = max(nums[0], nums[1]);
		for (int i = 3; i <= len; i++)
		{
			dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
		}
		return dp[len];
	}
};

int main()
{
	vector<int> v{ 7,5,6,5,4,33,5,9,10 };
	cout << Solution().rob(v) << endl;
	return 0;
}