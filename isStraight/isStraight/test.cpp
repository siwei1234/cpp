#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	bool isStraight(vector<int>& nums) {
		bool tmp[14];
		memset(tmp, 0, sizeof(tmp));
		int min = 14, max = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0)
				continue;
			if (tmp[nums[i]])
				return false;
			tmp[nums[i]] = true;
			if (min > nums[i])
				min = nums[i];
			if (max < nums[i])
				max = nums[i];
		}
		return max - min + 1 <= 5;
	}
};
int main()
{
	vector<int> nums{ 1,2,0,0,5 };
	cout << Solution().isStraight(nums) << endl;
	return 0;
}