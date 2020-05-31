#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<queue>
#include<vector>
using namespace std;


class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		priority_queue<int, vector<int>, greater<int>> minHeap;
		for (int i = 0; i < k; i++)
		{
			minHeap.push(nums[i]);
		}
		for (int i = k; i < nums.size(); i++)
		{
			if (nums[i] > minHeap.top())
			{
				minHeap.pop();
				minHeap.push(nums[i]);
			}
		}
		return minHeap.top();
	}
};
int main()
{
	vector<int> nums{ 1,2,5,7,8,9,6,5,4,3 };
	cout << Solution().findKthLargest(nums, 4) << endl;
	return 0;
}