#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int len = nums.size();
		vector<int> tmp(len + 1, 0);
		for (auto e : nums)
			tmp[e]++;
		for (int i = 0; i <= len; i++)
			if (tmp[i] == 0)
				return i;
		return -1;
	}
};

int main()
{
	vector<int> nums{ 0,1,2,3,4,5,8,9,6 };
	cout << Solution().missingNumber(nums) << endl;
	return 0;
}