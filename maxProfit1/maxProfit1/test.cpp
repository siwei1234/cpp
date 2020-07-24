#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int maxProfit(vector<int>& prices) {
		if (prices.size() == 0)
			return 0;
		int minprices = prices[0];
		int maxprices = 0;
		for (int i = 1; i < prices.size(); i++)
		{
			minprices = min(minprices, prices[i]);
			maxprices = max(maxprices, prices[i] - minprices);
		}
		return maxprices;
	}
};
int main()
{
	vector<int> nums{ 7,1,5,3,6,4 };
	cout << Solution().maxProfit(nums) << endl;
	return 0;
}