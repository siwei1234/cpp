#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int longestMountain(vector<int>& A) {
		int n = A.size();
		vector<int> left(n, 0);
		for (int i = 1; i < n; i++)
		{
			if (A[i - 1] < A[i])
				left[i] = left[i - 1] + 1;
			else
				left[i] = 0;
		}
		vector<int> right(n, 0);
		for (int i = n - 2; i >= 0; i--)
		{
			if (A[i] > A[i + 1])
				right[i] = right[i + 1] + 1;
			else
				right[i] = 0;
		}
		int ret = 0;
		for (int i = 0; i < n; i++)
		{
			if (left[i] > 0 && right[i] > 0)
				ret = max(ret, left[i] + right[i] + 1);
		}
		return ret;
	}
};

int main()
{
	vector<int> v{ 2,1,4,7,3,2,5 };
	cout << Solution().longestMountain(v) << endl;
	return 0;
}