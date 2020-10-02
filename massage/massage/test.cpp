#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {
public:
	int massage(vector<int>& nums) {
		if (nums.empty())
			return 0;
		int dp0 = 0, dp1 = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int tdp0 = max(dp0, dp1);
			int tdp1 = dp0 + nums[i];
			dp0 = tdp0;
			dp1 = tdp1;
		}
		return max(dp0, dp1);
	}
};

int main()
{
	vector<int> nums = { 1,2,3,1 };
	cout << Solution().massage(nums);
	return 0;
}