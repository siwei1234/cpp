#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> tmp;
		for (auto e : nums1)
		{
			tmp[e]++;
		}
		vector<int> ret;
		for (auto e : nums2)
		{
			if (tmp.find(e) != tmp.end() && tmp[e] > 0)
			{
				ret.push_back(e);
				tmp[e]--;
			}
		}
		return ret;
	}
};

int main()
{
	vector<int> nums1{ 4,9,5 };
	vector<int> nums2{ 9,4,9,8,4 };
	vector<int> ret = Solution().intersect(nums1, nums2);
	for (auto e : ret)
		cout << e << endl;
	return 0;
}