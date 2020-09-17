#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int ret = nums[0] + nums[1] + nums[2];
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++)
		{
			int begin = i + 1;
			int end = nums.size() - 1;
			while (begin < end)
			{
				int sum = nums[i] + nums[begin] + nums[end];
				if (abs(sum - target) < abs(ret - target))
				{
					ret = sum;
				}
				if (sum < target)
					++begin;
				else if (sum > target)
					--end;
				else
					return ret;
			}
		}
		return ret;
	}
};
int main()
{
	vector<int> nums{ 0,2,1,-3 };
	cout << Solution().threeSumClosest(nums, 1) << endl;
	return 0;
}