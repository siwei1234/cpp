#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int ret = 1;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] != nums[i + 1])
				nums[ret++] = nums[i + 1];
		}
		return ret;
	}
};

int main()
{
	vector<int> nums{ 1,1,1,2,2,2,5,5,7,8,8,9 };
	cout << Solution().removeDuplicates(nums) << endl;
	return 0;
}