#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<map>
#include<vector>
using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		map<int, int> ret;
		for (int i = 0; i < nums.size(); i++)
		{
			ret[nums[i]]++;
		}
		for (auto e : ret)
		{
			if (e.second > 1)
				return true;
		}
		return false;
	}
};

int main()
{
	vector<int> nums{ 1,1,1,3,3,4,3,2,4,2 };
	cout << Solution().containsDuplicate(nums) << endl;
	return 0;
}