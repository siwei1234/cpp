#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
		vector<int> v(101, 0);
		for (int i = 0; i < nums.size(); i++)
		{
			v[nums[i]]++;
		}
		for (int i = 1; i < 101; i++)
		{
			v[i] += v[i - 1];
		}
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++)
		{
			ret.push_back(nums[i] == 0 ? 0 : v[nums[i] - 1]);
		}
		return ret;
	}
};

int main()
{
	vector<int> nums = { 5,2,10,8,65,40 };
	vector<int> ret = Solution().smallerNumbersThanCurrent(nums);
	for (auto& i : ret)
	{
		cout << i << " ";
	}
	cout << endl;
	return 0;
}