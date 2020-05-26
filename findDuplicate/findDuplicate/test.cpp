#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
		int left = 1;
		int right = nums.size() - 1;
		while (left < right)
		{
			int mid = (left + right) >> 1;
			int cnt = 0;
			for (auto e : nums)
			{
				if (e <= mid)
					cnt++;
			}
			if (cnt > mid)
				right = mid;
			else
				left = mid + 1;
		}
		return left;
	}
};

int main()
{
	vector<int> nums{ 1,2,3,4,5,6,7,8,9,5 };
	cout << Solution().findDuplicate(nums) << endl;
	return 0;
}