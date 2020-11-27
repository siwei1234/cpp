#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int i = 0, j = 0;
		while (j < nums.size())
		{
			if (nums[j])
			{
				swap(nums[i], nums[j]);
				i++;
			}
			j++;
		}
	}
};


int main()
{
	vector<int> nums = { 0,1,0,3,12 };
	Solution().moveZeroes(nums);
	for (auto&i : nums)
		cout << i << " ";
	cout << endl;
	return 0;
}