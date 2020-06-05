#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		int len = nums.size();
		vector<int> ret(len);
		ret[0] = 1;
		for (int i = 1; i < len; i++)
			ret[i] = nums[i - 1] * ret[i - 1];
		int sum = 1;
		for (int i = len - 1; i >= 0; i--)
		{
			ret[i] = ret[i] * sum;
			sum *= nums[i];
		}
		return ret;
	}
};

int main()
{
	vector<int> nums{ 1,2,3,4,5,6 };
	vector<int> ret = Solution().productExceptSelf(nums);
	for (auto e : ret)
	{
		cout << e << " ";
	}
	return 0;
}