#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		int ret = 0;
		int mx = A[0];
		for (int i = 1; i < A.size(); i++)
		{
			ret = max(ret, mx + A[i] - i);
			mx = max(mx, A[i] + i);
		}
		return ret;
	}
};

int main()
{
	vector<int> A{ 8,1,5,2,6 };
	cout << Solution().maxScoreSightseeingPair(A) << endl;
	return 0;
}