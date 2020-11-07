#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	int countRangeSumRecursive(vector<long>& sum, int lower, int upper, int left, int right) {
		if (left == right) {
			return 0;
		}
		else {
			int mid = (left + right) / 2;
			int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
			int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
			int ret = n1 + n2;

			// ����ͳ���±�Ե�����
			int i = left;
			int l = mid + 1;
			int r = mid + 1;
			while (i <= mid) {
				while (l <= right && sum[l] - sum[i] < lower) l++;
				while (r <= right && sum[r] - sum[i] <= upper) r++;
				ret += (r - l);
				i++;
			}

			// ���ϲ�������������
			vector<int> sorted(right - left + 1);
			int p1 = left, p2 = mid + 1;
			int p = 0;
			while (p1 <= mid || p2 <= right) {
				if (p1 > mid) {
					sorted[p++] = sum[p2++];
				}
				else if (p2 > right) {
					sorted[p++] = sum[p1++];
				}
				else {
					if (sum[p1] < sum[p2]) {
						sorted[p++] = sum[p1++];
					}
					else {
						sorted[p++] = sum[p2++];
					}
				}
			}
			for (int i = 0; i < sorted.size(); i++) {
				sum[left + i] = sorted[i];
			}
			return ret;
		}
	}

	int countRangeSum(vector<int>& nums, int lower, int upper) {
		long s = 0;
		vector<long> sum{ 0 };
		for (auto& v : nums) {
			s += v;
			sum.push_back(s);
		}
		return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
	}
};

int main()
{
	vector<int> nums = { -2,5,-1 };
	cout << Solution().countRangeSum(nums, -2, 2) << endl;
	return 0;
}