#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


class Solution {
public:
	int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end());
		for (int i = A.size() - 1; i >= 2; i--)
		{
			if (A[i - 1] + A[i - 2] > A[i])
			{
				return A[i - 1] + A[i - 2] + A[i];
			}
		}
		return 0;
	}
};

int main()
{
	vector<int> A = { 3,6,2,3 };
	cout << Solution().largestPerimeter(A) << endl;
	return 0;
}