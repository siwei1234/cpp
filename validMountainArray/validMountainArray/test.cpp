#define _CRT_SECURE_NO_WARNINGS 1


#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
	bool validMountainArray(vector<int>& A) {
		int n = A.size();
		int i = 0;
		while (i + 1 < n && A[i + 1] > A[i])
			i++;
		if (i == 0 || i == n - 1)
			return false;
		while (i + 1 < n && A[i] > A[i + 1])
			i++;
		return i == n - 1;
	}
};


int main()
{
	vector<int> A = { 0,3,2,1 };
	cout << Solution().validMountainArray(A) << endl;
	return 0;
}