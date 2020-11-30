#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maximumGap(vector<int>& nums) {
		if (nums.size() < 2)
			return 0;
		sort(nums.begin(), nums.end());
		int ret = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			int val = nums[i + 1] - nums[i];
			if (val > ret)
				ret = val;
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = { 1,5,8,6,4,1,2,45,24,85,69 };
	cout << Solution().maximumGap(nums) << endl;
	return 0;
}