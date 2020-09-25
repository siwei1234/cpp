#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {
		int val = 0;
		int i;
		for (i = 0; i < nums.size(); i++)
		{
			val ^= nums[i];
		}
		for (i = 0; i < 32; i++)
		{
			if ((val >> i) & 1)
				break;
		}
		vector<int> ret(2, 0);
		for (int j = 0; j < nums.size(); j++)
		{
			if ((nums[j] >> i) & 1)
				ret[0] ^= nums[j];
			else
				ret[1] ^= nums[j];
		}
		return ret;
	}
};
int main()
{
	vector<int> nums{ 1,1,2,2,3,3,5,7 };
	vector<int> ret = Solution().singleNumber(nums);
	for (auto e : ret)
	{
		cout << e << endl;
	}
	return 0;
}