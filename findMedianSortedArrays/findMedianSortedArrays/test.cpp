#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int len1 = nums1.size();
		int len2 = nums2.size();
		if (len1 > len2)
			return findMedianSortedArrays(nums2, nums1);
		int l1, l2, r1, r2, c1, c2, l = 0, r = len1 * 2;
		while (l <= r)
		{
			c1 = (l + r) >> 1;
			c2 = len1 + len2 - c1;
			l1 = (c1 == 0) ? INT_MIN : nums1[(c1 - 1) / 2];
			r1 = (c1 == 2 * len1) ? INT_MAX : nums1[c1 / 2];
			l2 = (c2 == 0) ? INT_MIN : nums2[(c2 - 1) / 2];
			r2 = (c2 == 2 * len2) ? INT_MAX : nums2[c2 / 2];
			if (l1 > r2)
				r = c1 - 1;
			else if (l2 > r1)
				l = c1 + 1;
			else
				break;
		}
		return (max(l1, l2) + min(r1, r2)) / 2.0;
	}
};


int main()
{
	vector<int> nums1{ 1,2,3,4,5,6 };
	vector<int> nums2{ 7,8 };
	cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}