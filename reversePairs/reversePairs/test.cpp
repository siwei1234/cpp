#define _CRT_SECURE_NO_WARNINGS 1



#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

	int reversePairsRecursive(vector<int>& nums, int left, int right)
	{
		if (left == right)
			return 0;
		int mid = (left + right) / 2;
		int r1 = reversePairsRecursive(nums, left, mid);
		int r2 = reversePairsRecursive(nums, mid + 1, right);
		int ret = r1 + r2;
		int i = left;
		int j = mid + 1;
		while (i <= mid)
		{
			while (j <= right && (long long)nums[i] > 2 * (long long)nums[j])
				j++;
			ret += (j - mid - 1);
			i++;
		}
		vector<int> sorted(right - left + 1);
		int p1 = left, p2 = mid + 1;
		int p = 0;
		while (p1 <= mid || p2 <= right)
		{
			if (p1 > mid)
				sorted[p++] = nums[p2++];
			else if (p2 > right)
				sorted[p++] = nums[p1++];
			else
			{
				if (nums[p1] < nums[p2])
					sorted[p++] = nums[p1++];
				else
					sorted[p++] = nums[p2++];
			}
		}
		for (int i = 0; i < sorted.size(); i++)
			nums[i + left] = sorted[i];
		return ret;
	}

	int reversePairs(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		return reversePairsRecursive(nums, 0, nums.size() - 1);
	}
};

int main()
{
	vector<int> nums = { 2,4,3,5,1 };
	cout << Solution().reversePairs(nums) << endl;
	return 0;
}