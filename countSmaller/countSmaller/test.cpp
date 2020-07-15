#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> countSmaller(vector<int>& nums) {
		vector<int>t, res(nums.size());
		for (int i = nums.size() - 1; i >= 0; i--) {
			int left = 0, right = t.size();
			while (left < right) {
				int mid = left + (right - left) / 2;
				if (t[mid] >= nums[i]) {
					right = mid;
				}
				else {
					left = mid + 1;
				}
			}
			res[i] = right;
			t.insert(t.begin() + right, nums[i]);
		}
		return res;
	}
};

int main()
{
	vector<int> nums{ 5,2,6,1 };
	vector<int> ret = Solution().countSmaller(nums);
	for(auto e : ret)
		cout << e << endl;
	return 0;
}