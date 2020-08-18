#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int search(vector<int>& nums, int target) {
		if (nums.empty())
			return 0;
		int left = 0;
		int right = nums.size() - 1;
		int mid;
		while (left < right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] >= target)
				right = mid;
			else
				left = mid + 1;
		}
		if (nums[left] != target)
			return 0;
		int prev = left;
		right = nums.size();
		while (left < right)
		{
			mid = (left + right) >> 1;
			if (nums[mid] <= target)
				left = mid + 1;
			else
				right = mid;
		}
		return left - prev;
	}
};
int main()
{
	int nums[] = { 5,7,7,8,8,10 };
	vector<int> v(nums, nums + 7);
	cout << Solution().search(v, 7);
	return 0;
}