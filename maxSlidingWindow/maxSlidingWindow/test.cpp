#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		int n = nums.size();
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < k; ++i) {
			q.emplace(nums[i], i);
		}
		vector<int> ans = { q.top().first };
		for (int i = k; i < n; ++i) {
			q.emplace(nums[i], i);
			while (q.top().second <= i - k) {
				q.pop();
			}
			ans.push_back(q.top().first);
		}
		return ans;
	}
};

int main()
{
	vector<int> nums = { 1,3,-1,-3,5,3,6,7 };
	vector<int> ret = Solution().maxSlidingWindow(nums, 3);
	for (auto& i : ret)
		cout << i << " ";
	cout << endl;
	return 0;
}