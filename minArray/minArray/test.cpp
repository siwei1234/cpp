#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int minArray(vector<int>& numbers) {
		int left = 0;
		int right = numbers.size() - 1;
		while (left < right)
		{
			int mid = left + right >> 1;
			if (numbers[right] > numbers[mid])
			{
				right = mid;
			}
			else if (numbers[right] < numbers[mid])
			{
				left = mid + 1;
			}
			else
				right--;
		}
		return numbers[right];
	}
};

int main()
{
	vector<int> nums{ 3,4,5,1,2 };
	cout << Solution().minArray(nums) << endl;
	return 0;
}