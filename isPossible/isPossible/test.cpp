#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
	bool isPossible(vector<int>& nums) {
		unordered_map<int, int> countMap;
		unordered_map<int, int> endMap;
		for (auto& x : nums)
			countMap[x]++;
		for (auto& x : nums)
		{
			int count = countMap[x];
			if (count > 0)
			{
				int prevEndCount = endMap[x - 1];
				if (prevEndCount > 0)
				{
					countMap[x] = count - 1;
					endMap[x - 1] = prevEndCount - 1;
					endMap[x] = endMap[x] + 1;
				}
				else
				{
					int count1 = countMap[x + 1];
					int count2 = countMap[x + 2];
					if (count1 > 0 && count2 > 0)
					{
						countMap[x] = count - 1;
						countMap[x + 1] = count1 - 1;
						countMap[x + 2] = count2 - 1;
						endMap[x + 2] = endMap[x + 2] + 1;
					}
					else
						return false;
				}
			}
		}
		return true;
	}
};

int main()
{
	vector<int> nums = { 1,2,3,3,4,5 };
	cout << Solution().isPossible(nums) << endl;
	return 0;
}