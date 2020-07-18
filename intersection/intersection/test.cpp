#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<set>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
	{
		vector<int> ret;
		set<int> s(nums1.begin(), nums1.end());
		for (auto &i : nums2) {
			if (s.erase(i)) {
				ret.push_back(i);
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> nums1{ 1,2,2,1 };
	vector<int> nums2{ 2,2 };
	vector<int> ret = Solution().intersection(nums1, nums2);
	for (auto e : ret)
		cout << e << endl;
	return 0;
}