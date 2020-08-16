#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;



class Solution {
public:
	vector<int> twoSum(vector<int>& numbers, int target) {
		for (int i = 0; i < numbers.size(); i++)
		{
			int left = i + 1;
			int right = numbers.size() - 1;
			while (left <= right)
			{
				int mid = (right - left) / 2 + left;
				if (numbers[mid] == target - numbers[i])
				{
					return { i + 1, mid + 1 };
				}
				else if (numbers[mid] > target - numbers[i])
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
		}
		return { -1, -1 };
	}
};

int main()
{
	vector<int> nums = { 2, 7, 11, 15 };
	vector<int> ret = Solution().twoSum(nums, 9);
	for (auto e : ret)
		cout << e << " ";
	cout << endl;
	return 0;
}