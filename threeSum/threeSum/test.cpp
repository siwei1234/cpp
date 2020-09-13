#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		int len = nums.size();
		sort(nums.begin(), nums.end());
		vector<vector<int>> ret;
		for (int first = 0; first < len; first++)
		{
			if (first > 0 && nums[first] == nums[first - 1])
				continue;
			int third = len - 1;
			int target = -nums[first];
			for (int second = first + 1; second < len; second++)
			{
				if (second > first + 1 && nums[second] == nums[second - 1])
					continue;
				while (second < third && nums[second] + nums[third] > target)
				{
					--third;
				}
				if (second == third)
					break;
				if (nums[second] + nums[third] == target)
				{
					ret.push_back({ nums[first], nums[second], nums[third] });
				}
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> nums{ -1, 0, 1, 2, -1, -4 };
	vector<vector<int>> ret = Solution().threeSum(nums);
	for (auto e : ret)
	{
		for (auto n : e)
		{
			cout << n << " ";
		}
		cout << endl;
	}
	return 0;
}