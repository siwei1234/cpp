#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<map>
#include<vector>
using namespace std;
class Solution {
public:
	int majorityElement(vector<int>& nums) {
		map<int, int> m;
		for (int i = 0; i < nums.size(); i++)
		{
			m[nums[i]]++;
			if (m[nums[i]] > nums.size() / 2)
				return nums[i];
		}
		return -1;
	}
};

int main()
{
	vector<int> nums = { 1,2,5,9,5,9,5,5,5 };
	cout << Solution().majorityElement(nums) << endl;
	return 0;
}