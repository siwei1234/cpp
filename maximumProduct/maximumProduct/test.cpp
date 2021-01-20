#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
public:
	int maximumProduct(vector<int>& nums) {
		// ��С�ĺ͵ڶ�С��
		int min1 = INT_MAX, min2 = INT_MAX;
		// ���ġ��ڶ���ĺ͵������
		int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;

		for (int x : nums) {
			if (x < min1) {
				min2 = min1;
				min1 = x;
			}
			else if (x < min2) {
				min2 = x;
			}

			if (x > max1) {
				max3 = max2;
				max2 = max1;
				max1 = x;
			}
			else if (x > max2) {
				max3 = max2;
				max2 = x;
			}
			else if (x > max3) {
				max3 = x;
			}
		}

		return max(min1 * min2 * max1, max1 * max2 * max3);
	}
};

int main()
{
	vector<int> nums = { 1,5,8,7,66,44,-33,-68 };
	cout << Solution().maximumProduct(nums) << endl;
	return 0;
}