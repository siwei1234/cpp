#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int minSubArrayLen(int s, vector<int>& nums) {
		int ret = 0;
		int tmp = 0;
		int sum = 0;
		int j = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			sum += nums[i];
			tmp += 1;
			while (1)
			{
				if (sum >= s)
				{
					if (ret == 0)
						ret = tmp;
					else
						ret = min(ret, tmp);
				}
				else
				{
					break;
				}
				sum -= nums[j++];
				tmp--;
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> nums{ 2,3,1,2,4,3 };
	cout << Solution().minSubArrayLen(7, nums) << endl;
	return 0;
}