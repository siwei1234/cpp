#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int len = nums.size();
		for (int i = 0; i < len; i++)
		{
			while (nums[i] > 0 && nums[i] <= len && nums[nums[i] - 1] != nums[i])
				swap(nums[nums[i] - 1], nums[i]);
		}
		for (int i = 0; i < len; i++)
		{
			if (nums[i] != i + 1)
				return i + 1;
		}
		return len + 1;
	}
};

int main()
{
	vector<int> nums{ 3,4,-1,1 };
	cout << Solution().firstMissingPositive(nums) << endl;
	return 0;
}